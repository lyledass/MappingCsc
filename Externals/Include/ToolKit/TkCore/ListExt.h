#ifndef __TOOLKIT__EXTLIST_H
#define __TOOLKIT__EXTLIST_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/*
**
**	The definition of member template is outside the class. 
**	Visual C++ has a limitation in which member templates must be fully defined within the enclosing class.
**	See KB article Q239436 for more information about LNK2001 and member templates. 
**
*/

#define LISTEXT_NOKEY		-1
#define LISTEXT_ALLOCSTEP	50

template <class TYPE>
class CListExt {
public :

	enum LISTEXT_KEY_ORDER_STATE {
		LISTEXT_ORDERED_BYKEY_ASC = 0,		// liste tri�e par cl�e, par ordre croissant et "SANS TROUS" (pas d'utilisation de ResetAt)
		LISTEXT_ORDERED_BYKEY_DESC,			// liste tri�e par cl�e, par ordre d�croissant et "SANS TROUS" (pas d'utilisation de ResetAt)

		LISTEXT_ORDERED_NONE,				// �tat du tri par cl� inconnu
	};

	CListExt() {
		m_lpElementArray = NULL;
		m_lpKeyArray = NULL;
		m_elementAllocCount = NULL;
		m_elementCount = 0;
		m_iFirstFreeElement = -1;
		m_bAllowDuplicatedKey = false;
		m_iKeyOrderState = LISTEXT_ORDERED_BYKEY_ASC;
	};

		CListExt(const CListExt<TYPE> & Liste) 
		{
			m_lpElementArray = NULL;
			m_lpKeyArray = NULL;
			m_elementAllocCount = NULL;
			m_elementCount = 0;
			m_iFirstFreeElement = -1;
			m_bAllowDuplicatedKey = false;
			m_iKeyOrderState = LISTEXT_ORDERED_NONE;
			*this = Liste;
		};

	virtual ~CListExt() {
		if (m_lpElementArray) {
			for (int i = 0; i < m_elementCount; i++) {
				if (m_lpElementArray[i]) {
					delete m_lpElementArray[i];
					m_lpElementArray[i] = NULL;
				}
			}

			delete [] m_lpElementArray;
			m_lpElementArray = NULL;
		}

		if (m_lpKeyArray) {
			delete [] m_lpKeyArray;
			m_lpKeyArray = NULL;
		}

	};

	void AllowDuplicatedKey(bool bAllow) {
		m_bAllowDuplicatedKey = bAllow;
	}

	int	GetCount() const {
		return m_elementCount;
	};

	TYPE* GetByKey(long key) const {
		int	index;
		
		index = GetIndexByKey(key);
		if (index != -1)
			return GetAt(index);

		return NULL;
	};

	TYPE* GetAt(int	index) const {
		TYPE*	lpRes;

		lpRes = NULL;
		if (m_lpElementArray && (0 <= index) && (index < m_elementCount)) {
			lpRes = m_lpElementArray[index];
		}

		return lpRes;
	};

	// retourne l'index de l'element s'il en existe un exemplaire
	int GetIndex(const TYPE& elmt) const {
		int		index;

		for (index = 0; (index < m_elementCount); index++) {
			if (*(m_lpElementArray[index]) == elmt)
				return index;
		}

		return -1;
	};

	TYPE* operator[](int index) const
	{
		return GetAt(index);
	}

	long GetKeyAt(int index) const {
		long	res;

		res = LISTEXT_NOKEY;
		if (m_lpKeyArray && (0 <= index) && (index < m_elementCount)) {
			res = m_lpKeyArray[index];
		}
		
		return res;
	}

	long SetKeyAt(int index, long key) {
		long	res;

		res = LISTEXT_NOKEY;
		if (m_lpKeyArray && (0 <= index) && (index < m_elementCount)) {
			// on m�morise l'ancienne cl� pour la retourner
			res = m_lpKeyArray[index];

			// on met � jour la cl�
			m_lpKeyArray[index] = key;
		}
		
		return res;
	}
	

	void	AllocationTableau(	int iTailleTableau )
	{
		// Store old array size
		int iOldElementAllocCount = m_elementAllocCount;
		if( iTailleTableau > m_elementAllocCount )
		{
			int iAllocationStep = iTailleTableau - m_elementAllocCount;
	
			// on alloue ou r�alloue le tableau
			if (!m_lpElementArray) {
				m_lpElementArray = new TYPE*[iTailleTableau];
				if (m_lpElementArray) {
					m_elementAllocCount = iTailleTableau;
					memset(m_lpElementArray, 0, m_elementAllocCount);
				}
			}
			else {
				TYPE** lpElementArray = (TYPE**) realloc(m_lpElementArray, (iTailleTableau) * sizeof(TYPE*));
				if (lpElementArray) {
					m_lpElementArray = lpElementArray;
					memset(&m_lpElementArray[m_elementAllocCount], 0, iAllocationStep );
					m_elementAllocCount = iTailleTableau;
				}
			}

			if (!m_lpKeyArray) {
				m_lpKeyArray = new long[m_elementAllocCount];
				if (m_lpKeyArray)
					memset(m_lpKeyArray, LISTEXT_NOKEY, m_elementAllocCount);			
			}
			else {
				long* lpKeyArray = (long*) realloc(m_lpKeyArray, m_elementAllocCount * sizeof(long));
				if (lpKeyArray) {
					m_lpKeyArray = lpKeyArray;
					memset(&m_lpKeyArray[m_elementAllocCount - iAllocationStep], LISTEXT_NOKEY, iAllocationStep );
				} else {
					m_elementAllocCount = iOldElementAllocCount;
				}
			}
		}
	}

	int Add(const TYPE& elmt, 
			long key = LISTEXT_NOKEY, 
			bool bFillGap = false)			// indique si l'�l�ment ajout� doit remplacer un �l�ment vide de la liste
	{
		int		res;
		
		res = -1;

		if (!m_bAllowDuplicatedKey && (key != LISTEXT_NOKEY)) {
			// on recherche l'�l�ment avec la clef
			res = GetIndexByKey(key);
		}
		
		if (res == -1) {
			// on ajoute l'�l�ment � la liste
			if (m_elementCount >= m_elementAllocCount) 
				// Si on arrive � la limite des �l�ments allou�s, on augmente la taille du tableau courant
				AllocationTableau( m_elementAllocCount + LISTEXT_ALLOCSTEP );
			
			if (	!bFillGap					// On ne cherche pas � r�aliser de FillGap
				||	(m_iFirstFreeElement < 0))	// On a pas de position de premier �l�ment libre (on doit donc ajouter en fin de liste)
			{
				if (m_lpElementArray && (m_elementCount < m_elementAllocCount)) {
					m_lpElementArray[m_elementCount] = new TYPE();

					if (m_lpElementArray[m_elementCount]){
						*(m_lpElementArray[m_elementCount]) = elmt;
						m_lpKeyArray[m_elementCount] = key;

						res = m_elementCount;
						if (m_iFirstFreeElement == m_elementCount) {
							m_iFirstFreeElement++;
						}
						m_elementCount++;

						// V�rification de l'int�grit� du tri des cl�s
						if ((m_iKeyOrderState != LISTEXT_ORDERED_NONE) && (m_elementCount >= 2)) {
							if (m_iKeyOrderState == LISTEXT_ORDERED_BYKEY_ASC) {
								if (m_lpKeyArray[m_elementCount - 2] > m_lpKeyArray[m_elementCount - 1]) {
									// On avait pr�cis� que la liste �tait ordonn�e par ordre croissant
									// Cette insertion rompt l'�tat de tri
									if (m_elementCount == 2) {
										// On vient de faire l'ajout du deuxi�me �l�ment
										// Il s'agit d'un ordre d�croissant (l'ordre est positionn� � croissant � l'initialisation)
										m_iKeyOrderState = LISTEXT_ORDERED_BYKEY_DESC;
									} else {
										m_iKeyOrderState = LISTEXT_ORDERED_NONE;
									}
								} else {
									// L'int�grit� de l'ordre des cl�s est respect�e
								}
							} else {
								if (m_lpKeyArray[m_elementCount - 2] < m_lpKeyArray[m_elementCount - 1]) {
									// On avait pr�cis� que la liste �tait ordonn�e par ordre d�croissant
									// Cette insertion rompt l'�tat de tri
									m_iKeyOrderState = LISTEXT_ORDERED_NONE;
								} else {
									// L'int�grit� de l'ordre des cl�s est respect�e
								}
							}
						}
				
					}
				}
			} else {	// On a une position de premier �l�ment vide sauvegard�e

				// On ne g�re pas l'�tat de tri d'une liste � "trous"
				m_iKeyOrderState = LISTEXT_ORDERED_NONE;

				if (m_lpElementArray && (m_lpElementArray[m_iFirstFreeElement] == NULL)) {
					// Visiblement la position sauvegard�e est bien vide, on la remplie
					m_lpElementArray[m_iFirstFreeElement] = new TYPE();
					*(m_lpElementArray[m_iFirstFreeElement]) = elmt;
					m_lpKeyArray[m_iFirstFreeElement] = key;

					res = m_iFirstFreeElement;

					// on recherche l'emplacement libre suivant
					UpdateNextFreePosition();
				} else {
					// Position non vide ou tableau non allou�
					// On repasse par un Add classique sans FillGap
					m_iFirstFreeElement = -1;
					res = Add(elmt, key, false);
				}
			}
		}

		return res;
	};

	void	Clear() {
		// on d�truit tous les �l�ments
		if (m_lpElementArray) {
			for (int i = 0; i < m_elementCount; i++) {
				if (m_lpElementArray[i]) {
					delete m_lpElementArray[i];
					m_lpElementArray[i] = NULL;
				}
			}

			delete [] m_lpElementArray;
			m_lpElementArray = NULL;
		}

		if (m_lpKeyArray) {
			delete [] m_lpKeyArray;
			m_lpKeyArray = NULL;
		}
		m_elementCount = 0;
		m_elementAllocCount = 0;
		m_iFirstFreeElement = -1;
		m_iKeyOrderState = LISTEXT_ORDERED_BYKEY_ASC;
	};

	void	ResetAtKey(int	key) {
		int		index;

		index = GetIndexByKey(key);
		if (index != -1)
			ResetAt(index);
	};

	void	ResetAt(int	index) {
		// on d�truit l'�l�ment index�
		if (m_lpElementArray) {
			if (m_lpElementArray[index]) {
				delete m_lpElementArray[index];
				m_lpElementArray[index] = NULL;
				
				if (m_elementCount > index) {					// Pour sauvegarder le 1er �l�ment, on v�rifie qu'il est bien dans la liste ([0..m_elementCount-1])
					if (	(m_iFirstFreeElement == -1)			// Aucun �l�ment vide sauvegard�
						||	(m_iFirstFreeElement > index)) {	// �l�ment vide sauvegard� mais postion sup�rieur � la position courante
						// On sauvegarde le premier �l�ment vide de la liste
						m_iFirstFreeElement = index;
					}
				}
			}
		}
		
		if (m_lpKeyArray) {
			m_lpKeyArray[index] = LISTEXT_NOKEY;
		}
		
		// On ne g�re pas l'�tat de tri d'une liste � "trous"
		m_iKeyOrderState = LISTEXT_ORDERED_NONE;
	};

	void	RemoveLast() {
		if (m_elementCount > 0) {
			m_elementCount--;
			ResetAt(m_elementCount);
		}
	};

	void	RemoveAt(int	index) {
		InvertAt(index, m_elementCount-1);
		RemoveLast();
	};

	void	RemoveAtKey(int	key) {
		int		index;

		index = GetIndexByKey(key);
		if (index != -1)
			RemoveAt(index);
	};

	void RemoveNullObject() {
		for (int i = 0; i < m_elementCount; i++) {
			if (!m_lpElementArray[i]) {
				// L'�l�ment est NULL (on ne perd pas de temps avec lui, on le d�truit)
				// => d�placement � la fin et suppression de la liste (un �l�ment en moins � traiter)
				RemoveAt(i);
				// On revient sur l'�l�ment courant (le iBase++ va avoir lieu � la prochaine it�ration de la liste)
				// => le removeAt va sortir l'�l�ment courant de la liste et y coller le dernier �l�ment
				i--;
			}
		}
		
		// L'instruction Remove change l'ordre des �l�ments,
		// le cas �ch�ant, l'indicateur "m_iKeyOrderState" est automatiquement positionn� � la valeur LISTEXT_ORDERED_NONE
	}

	const CListExt<TYPE>& operator =(const CListExt<TYPE> &listExt) {
		int i;

		// Pour �viter l'auto-affectation
		if (this != &listExt) {
			this->Clear();
			this->AllowDuplicatedKey(listExt.GetAllowDuplicatedKey());
			this->AllocationTableau( listExt.m_elementCount );
			this->m_iKeyOrderState = listExt.m_iKeyOrderState;

			for (i = 0; i < listExt.GetCount(); i++) {
				if (listExt.GetAt(i)) {
					this->Add(*listExt.GetAt(i), listExt.GetKeyAt(i));
				}
			}
		}

		return (*this);
	};

	bool InvertAt(int indexA, int indexB) {
		TYPE*	lpTmp;
		long	keyTmp;
		bool	res;
		int		iMinIndex,
				iMaxIndex;

		res = false;

		if (indexA == indexB) {
			res = true;
		} else if (m_lpElementArray && m_lpKeyArray
			&& (0 <= indexA) && (indexA < m_elementCount)
			&& (0 <= indexB) && (indexB < m_elementCount))
		{
			lpTmp = m_lpElementArray[indexA];
			keyTmp = m_lpKeyArray[indexA];

			m_lpElementArray[indexA] = m_lpElementArray[indexB];
			m_lpKeyArray[indexA] = m_lpKeyArray[indexB];

			m_lpElementArray[indexB] = lpTmp;
			m_lpKeyArray[indexB] = keyTmp;

			if (indexA < indexB) {
				iMinIndex = indexA;
				iMaxIndex = indexB;
			} else {
				iMinIndex = indexB;
				iMaxIndex = indexA;
			}

			if (	(m_iFirstFreeElement <= iMaxIndex)
				&&	(m_iFirstFreeElement >= iMinIndex)) {
					if (m_lpElementArray[iMinIndex] == NULL) {
						// On a un �l�ment Null � une position inf�rieure
						m_iFirstFreeElement = iMinIndex;
					} else if (m_lpElementArray[iMaxIndex] == NULL) {
						// On a un �l�ment Null � la derni�re position invers�e
						// Normalement c'est signe qu'on a "m_iFirstFreeElement == iMinIndex"
						// Du coup on va chercher le premier �l�ment Null � partir du premier �l�ment invers�
						m_iFirstFreeElement = iMinIndex;
						UpdateNextFreePosition();
					}
			}
			// On ne g�re pas le r�sultat d'une inversion sur le tri de la liste de cl� :
			// la liste est alors d�clar�e comme "non tri�e par cl�"
			m_iKeyOrderState = LISTEXT_ORDERED_NONE;
		}

		return res;
	};

	void Sort(bool BinaryPredicate(const TYPE& typeA, const TYPE& typeB))
	{
		int		iBase;
		int		iMin;
		int		iIndex;

		// On supprimer les objets NULL de la liste en premier (ils ralentissent inutilement le traitement)
		RemoveNullObject();

		for (iBase = 0; iBase < (m_elementCount - 1); iBase++) {
			iMin = iBase;

			for (iIndex = (iBase + 1); iIndex < m_elementCount; iIndex++) {
				if (!BinaryPredicate(*m_lpElementArray[iMin], *m_lpElementArray[iIndex])) { // Ne peuvent �tre NULL => RemoveNullObject s'en ait charg�
					iMin = iIndex;
				}
			}

			if (iMin != iBase) {
				InvertAt(iMin, iBase);
			}
		}
		// On ne g�re pas le r�sultat d'un tri de la liste par �l�ment :
		// la liste est alors d�clar�e comme "non tri�e par cl�"
		m_iKeyOrderState = LISTEXT_ORDERED_NONE;
	}

	bool SortEx(bool BinaryPredicate(const TYPE* pTypeA, const TYPE* pTypeB, void* pData), void* pData)
	{
		int		iBase;
		int		iMin;
		int		iIndex;

		// On supprimer les objets NULL de la liste en premier (ils ralentissent inutilement le traitement)
		RemoveNullObject();

		for (iBase = 0; iBase < (m_elementCount - 1); iBase++) {
			iMin = iBase;

			for (iIndex = (iBase + 1); iIndex < m_elementCount; iIndex++) {
				if (!BinaryPredicate(m_lpElementArray[iMin], m_lpElementArray[iIndex], pData)) { // Ne peuvent �tre NULL => RemoveNullObject s'en ait charg�
					iMin = iIndex;
				}
			}

			if (iMin != iBase) {
				InvertAt(iMin, iBase);
			}
		}
		// On ne g�re pas le r�sultat d'un tri de la liste par �l�ment :
		// la liste est alors d�clar�e comme "non tri�e par cl�"
		m_iKeyOrderState = LISTEXT_ORDERED_NONE;
		return true;
	};

	void SortByKey(bool bOrdreCroissant) {
		int		iBase;
		int		iMin;
		int		iIndex;

		// On supprimer les objets NULL de la liste en premier (ils ralentissent inutilement le traitement)
		RemoveNullObject();

		// On �vite de faire des algo de calculs inutiles si la liste est d�j� tri�e
		if (!VerifyListOrder(bOrdreCroissant)) {
			// On copie-colle les boucles "for" (moins d'instructions de tests sur la variable "bOrdreCroissant" => plus efficace)
			if (bOrdreCroissant) {
				// Ordre d�croissant
				for (iBase = 0; iBase < (m_elementCount - 1); iBase++) {
					iMin = iBase;

					for (iIndex = (iBase + 1); iIndex < m_elementCount; iIndex++) {
						if (m_lpKeyArray[iIndex] < m_lpKeyArray[iMin]) {
							iMin = iIndex;
						}
					}

					if (iMin != iBase) {
						InvertAt(iMin, iBase);
					}
				}
			} else {
				// Ordre d�croissant
				for (iBase = 0; iBase < (m_elementCount - 1); iBase++) {
					iMin = iBase;

					for (iIndex = (iBase + 1); iIndex < m_elementCount; iIndex++) {
						if (m_lpKeyArray[iMin] < m_lpKeyArray[iIndex]) {
							iMin = iIndex;
						}
					}

					if (iMin != iBase) {
						InvertAt(iMin, iBase);
					}
				}
			}
		}
		
		// Tri�e par cl�
		m_iKeyOrderState = bOrdreCroissant ? LISTEXT_ORDERED_BYKEY_ASC : LISTEXT_ORDERED_BYKEY_DESC;
	};

	bool GetAllowDuplicatedKey() const {
		return m_bAllowDuplicatedKey;
	}

	int	GetIndexByKey(long key) const {
		int		index;

		if (	(m_iKeyOrderState == LISTEXT_ORDERED_BYKEY_ASC)
			||	(m_iKeyOrderState == LISTEXT_ORDERED_BYKEY_DESC)
			)
		{
			// La liste est tri�e par cl�, on r�alise une recherche dichotomique : plus efficace!
			return GetIndexByKeyDichotomique(key);
		} else {
			for (index = 0; index < m_elementCount; index++) {
				if (m_lpKeyArray[index] == key)
					return index;
			}
		}

		return -1;
	};

private :
	
	int	GetIndexByKeyDichotomique(long key) const {
		int		iCurrentPos;
		int		iBeginPos;
		int		iEndPos;

		if (m_lpKeyArray && (m_elementCount > 0)) {
			iBeginPos = 0;
			iEndPos = m_elementCount - 1;
			// On copie-colle les boucles "while" (moins d'instructions de tests sur la variable "m_iKeyOrderState" => plus efficace)
			if (m_iKeyOrderState == LISTEXT_ORDERED_BYKEY_ASC) {
				// Ordre ascendant
				if (key > m_lpKeyArray[iEndPos]) {
					// Cl� hors limite : inutile de chercher
					return -1;
				}
				if (key < m_lpKeyArray[iBeginPos]) {
					// Cl� hors limite : inutile de chercher
					return -1;
				}

				while (iBeginPos <= iEndPos) {
					iCurrentPos = iBeginPos + ((iEndPos - iBeginPos) / 2);
					if (m_lpKeyArray[iCurrentPos] == key) {
						// On a trouv� l'�l�ment qui nous int�resse, on quitte im�diatement la boucle et la fonction (�conomie d'instruction)
						return iCurrentPos;
					} else if (m_lpKeyArray[iCurrentPos] > key) {
						// On continue la recherche
						iEndPos = iCurrentPos - 1;
					} else {
						// On continue la recherche
						iBeginPos = iCurrentPos + 1;
					}
				}
			} else if (m_iKeyOrderState == LISTEXT_ORDERED_BYKEY_DESC) {
				// Ordre descendant
				if (key < m_lpKeyArray[iEndPos]) {
					// Cl� hors limite : inutile de chercher
					return -1;
				}
				if (key > m_lpKeyArray[iBeginPos]) {
					// Cl� hors limite : inutile de chercher
					return -1;
				}
				while (iBeginPos <= iEndPos) {
					iCurrentPos = iBeginPos + ((iEndPos - iBeginPos) / 2);
					if (m_lpKeyArray[iCurrentPos] == key) {
						// On a trouv� l'�l�ment qui nous int�resse, on quitte im�diatement la boucle et la fonction (�conomie d'instruction)
						return iCurrentPos;
					} else if (m_lpKeyArray[iCurrentPos] > key) {
						// On continue la recherche
						iBeginPos = iCurrentPos + 1;
					} else {
						// On continue la recherche
						iEndPos = iCurrentPos - 1;
					}
				}
			}
		}
		// Si on arrive ici : on a pas trouv� la cl� que l'on cherchait
		return -1;
	};

	// Fonction qui v�rifie l'int�grit� du tri sur la liste compl�te (�vite de gaspiller du temps de calcul sur une liste d�j� tri�e)
	bool VerifyListOrder(bool bOrdreCroissant) {
		bool	bListOrdered;

		bListOrdered = true;
		if (bOrdreCroissant) {
			for (int i = 0; (i < (m_elementCount - 1)) && bListOrdered; i++) {
				if (m_lpKeyArray[i] > m_lpKeyArray[i + 1]) {
					bListOrdered = false;
				}
			}
		} else {
			for (int i = 0; (i < (m_elementCount - 1)) && bListOrdered; i++) {
				if (m_lpKeyArray[i] < m_lpKeyArray[i + 1]) {
					bListOrdered = false;
				}
			}
		}
		return bListOrdered;
	}

	void UpdateNextFreePosition() {
		bool	bContinue;

		bContinue = true;
		// On boucle sur la seconde partie de la liste
		for (int index = m_iFirstFreeElement + 1; index < m_elementCount && bContinue; index++) {
			if (m_lpElementArray && m_lpElementArray[index] == NULL) {
				// On a trouv� un �l�ment vide
				// On arrete la recherche
				bContinue = false;
				m_iFirstFreeElement = index;
			}
		}

		if (bContinue) {
			// On a pas arr�t� la recherche en cours de parcours
			// On a donc pas trouv� d'�l�ment vide
			m_iFirstFreeElement = -1;
		}
	}

	TYPE**					m_lpElementArray;		///< Tableau d'�l�ments de tarification
	long*					m_lpKeyArray;			///< Tableau des clefs pour acc�s rapides
	int						m_elementAllocCount;	///< Nombre d'�l�ments allou�s

	int						m_elementCount;			///< Nombre d'�l�ments actifs
	int						m_iFirstFreeElement;	///< Premier �l�ment NULL de la liste (pour le fillGap)

	bool					m_bAllowDuplicatedKey;	///< Autorise ou non plusieurs �l�ments avec la m�me clef

	LISTEXT_KEY_ORDER_STATE	m_iKeyOrderState;		///< Indicateur de l'�tat de tri de la liste (tri par cl� pour la recherche dichotomique du GetByKey)
};

#endif /* __TOOLKIT__EXTLIST_H */
