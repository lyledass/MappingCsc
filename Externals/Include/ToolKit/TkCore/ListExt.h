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
		LISTEXT_ORDERED_BYKEY_ASC = 0,		// liste triée par clée, par ordre croissant et "SANS TROUS" (pas d'utilisation de ResetAt)
		LISTEXT_ORDERED_BYKEY_DESC,			// liste triée par clée, par ordre décroissant et "SANS TROUS" (pas d'utilisation de ResetAt)

		LISTEXT_ORDERED_NONE,				// état du tri par clé inconnu
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
			// on mémorise l'ancienne clé pour la retourner
			res = m_lpKeyArray[index];

			// on met à jour la clé
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
	
			// on alloue ou réalloue le tableau
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
			bool bFillGap = false)			// indique si l'élément ajouté doit remplacer un élément vide de la liste
	{
		int		res;
		
		res = -1;

		if (!m_bAllowDuplicatedKey && (key != LISTEXT_NOKEY)) {
			// on recherche l'élément avec la clef
			res = GetIndexByKey(key);
		}
		
		if (res == -1) {
			// on ajoute l'élément à la liste
			if (m_elementCount >= m_elementAllocCount) 
				// Si on arrive à la limite des éléments alloués, on augmente la taille du tableau courant
				AllocationTableau( m_elementAllocCount + LISTEXT_ALLOCSTEP );
			
			if (	!bFillGap					// On ne cherche pas à réaliser de FillGap
				||	(m_iFirstFreeElement < 0))	// On a pas de position de premier élément libre (on doit donc ajouter en fin de liste)
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

						// Vérification de l'intégrité du tri des clés
						if ((m_iKeyOrderState != LISTEXT_ORDERED_NONE) && (m_elementCount >= 2)) {
							if (m_iKeyOrderState == LISTEXT_ORDERED_BYKEY_ASC) {
								if (m_lpKeyArray[m_elementCount - 2] > m_lpKeyArray[m_elementCount - 1]) {
									// On avait précisé que la liste était ordonnée par ordre croissant
									// Cette insertion rompt l'état de tri
									if (m_elementCount == 2) {
										// On vient de faire l'ajout du deuxième élément
										// Il s'agit d'un ordre décroissant (l'ordre est positionné à croissant à l'initialisation)
										m_iKeyOrderState = LISTEXT_ORDERED_BYKEY_DESC;
									} else {
										m_iKeyOrderState = LISTEXT_ORDERED_NONE;
									}
								} else {
									// L'intégrité de l'ordre des clés est respectée
								}
							} else {
								if (m_lpKeyArray[m_elementCount - 2] < m_lpKeyArray[m_elementCount - 1]) {
									// On avait précisé que la liste était ordonnée par ordre décroissant
									// Cette insertion rompt l'état de tri
									m_iKeyOrderState = LISTEXT_ORDERED_NONE;
								} else {
									// L'intégrité de l'ordre des clés est respectée
								}
							}
						}
				
					}
				}
			} else {	// On a une position de premier élément vide sauvegardée

				// On ne gère pas l'état de tri d'une liste à "trous"
				m_iKeyOrderState = LISTEXT_ORDERED_NONE;

				if (m_lpElementArray && (m_lpElementArray[m_iFirstFreeElement] == NULL)) {
					// Visiblement la position sauvegardée est bien vide, on la remplie
					m_lpElementArray[m_iFirstFreeElement] = new TYPE();
					*(m_lpElementArray[m_iFirstFreeElement]) = elmt;
					m_lpKeyArray[m_iFirstFreeElement] = key;

					res = m_iFirstFreeElement;

					// on recherche l'emplacement libre suivant
					UpdateNextFreePosition();
				} else {
					// Position non vide ou tableau non alloué
					// On repasse par un Add classique sans FillGap
					m_iFirstFreeElement = -1;
					res = Add(elmt, key, false);
				}
			}
		}

		return res;
	};

	void	Clear() {
		// on détruit tous les éléments
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
		// on détruit l'élément indexé
		if (m_lpElementArray) {
			if (m_lpElementArray[index]) {
				delete m_lpElementArray[index];
				m_lpElementArray[index] = NULL;
				
				if (m_elementCount > index) {					// Pour sauvegarder le 1er élément, on vérifie qu'il est bien dans la liste ([0..m_elementCount-1])
					if (	(m_iFirstFreeElement == -1)			// Aucun élément vide sauvegardé
						||	(m_iFirstFreeElement > index)) {	// Élément vide sauvegardé mais postion supérieur à la position courante
						// On sauvegarde le premier élément vide de la liste
						m_iFirstFreeElement = index;
					}
				}
			}
		}
		
		if (m_lpKeyArray) {
			m_lpKeyArray[index] = LISTEXT_NOKEY;
		}
		
		// On ne gère pas l'état de tri d'une liste à "trous"
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
				// L'élément est NULL (on ne perd pas de temps avec lui, on le détruit)
				// => déplacement à la fin et suppression de la liste (un élément en moins à traiter)
				RemoveAt(i);
				// On revient sur l'élément courant (le iBase++ va avoir lieu à la prochaine itération de la liste)
				// => le removeAt va sortir l'élément courant de la liste et y coller le dernier élément
				i--;
			}
		}
		
		// L'instruction Remove change l'ordre des éléments,
		// le cas échéant, l'indicateur "m_iKeyOrderState" est automatiquement positionné à la valeur LISTEXT_ORDERED_NONE
	}

	const CListExt<TYPE>& operator =(const CListExt<TYPE> &listExt) {
		int i;

		// Pour éviter l'auto-affectation
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
						// On a un élément Null à une position inférieure
						m_iFirstFreeElement = iMinIndex;
					} else if (m_lpElementArray[iMaxIndex] == NULL) {
						// On a un élément Null à la dernière position inversée
						// Normalement c'est signe qu'on a "m_iFirstFreeElement == iMinIndex"
						// Du coup on va chercher le premier élément Null à partir du premier élément inversé
						m_iFirstFreeElement = iMinIndex;
						UpdateNextFreePosition();
					}
			}
			// On ne gère pas le résultat d'une inversion sur le tri de la liste de clé :
			// la liste est alors déclarée comme "non triée par clé"
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
				if (!BinaryPredicate(*m_lpElementArray[iMin], *m_lpElementArray[iIndex])) { // Ne peuvent être NULL => RemoveNullObject s'en ait chargé
					iMin = iIndex;
				}
			}

			if (iMin != iBase) {
				InvertAt(iMin, iBase);
			}
		}
		// On ne gère pas le résultat d'un tri de la liste par élément :
		// la liste est alors déclarée comme "non triée par clé"
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
				if (!BinaryPredicate(m_lpElementArray[iMin], m_lpElementArray[iIndex], pData)) { // Ne peuvent être NULL => RemoveNullObject s'en ait chargé
					iMin = iIndex;
				}
			}

			if (iMin != iBase) {
				InvertAt(iMin, iBase);
			}
		}
		// On ne gère pas le résultat d'un tri de la liste par élément :
		// la liste est alors déclarée comme "non triée par clé"
		m_iKeyOrderState = LISTEXT_ORDERED_NONE;
		return true;
	};

	void SortByKey(bool bOrdreCroissant) {
		int		iBase;
		int		iMin;
		int		iIndex;

		// On supprimer les objets NULL de la liste en premier (ils ralentissent inutilement le traitement)
		RemoveNullObject();

		// On évite de faire des algo de calculs inutiles si la liste est déjà triée
		if (!VerifyListOrder(bOrdreCroissant)) {
			// On copie-colle les boucles "for" (moins d'instructions de tests sur la variable "bOrdreCroissant" => plus efficace)
			if (bOrdreCroissant) {
				// Ordre décroissant
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
				// Ordre décroissant
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
		
		// Triée par clé
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
			// La liste est triée par clé, on réalise une recherche dichotomique : plus efficace!
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
					// Clé hors limite : inutile de chercher
					return -1;
				}
				if (key < m_lpKeyArray[iBeginPos]) {
					// Clé hors limite : inutile de chercher
					return -1;
				}

				while (iBeginPos <= iEndPos) {
					iCurrentPos = iBeginPos + ((iEndPos - iBeginPos) / 2);
					if (m_lpKeyArray[iCurrentPos] == key) {
						// On a trouvé l'élément qui nous intéresse, on quitte imédiatement la boucle et la fonction (économie d'instruction)
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
					// Clé hors limite : inutile de chercher
					return -1;
				}
				if (key > m_lpKeyArray[iBeginPos]) {
					// Clé hors limite : inutile de chercher
					return -1;
				}
				while (iBeginPos <= iEndPos) {
					iCurrentPos = iBeginPos + ((iEndPos - iBeginPos) / 2);
					if (m_lpKeyArray[iCurrentPos] == key) {
						// On a trouvé l'élément qui nous intéresse, on quitte imédiatement la boucle et la fonction (économie d'instruction)
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
		// Si on arrive ici : on a pas trouvé la clé que l'on cherchait
		return -1;
	};

	// Fonction qui vérifie l'intégrité du tri sur la liste complète (évite de gaspiller du temps de calcul sur une liste déjà triée)
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
				// On a trouvé un élément vide
				// On arrete la recherche
				bContinue = false;
				m_iFirstFreeElement = index;
			}
		}

		if (bContinue) {
			// On a pas arrêté la recherche en cours de parcours
			// On a donc pas trouvé d'élément vide
			m_iFirstFreeElement = -1;
		}
	}

	TYPE**					m_lpElementArray;		///< Tableau d'éléments de tarification
	long*					m_lpKeyArray;			///< Tableau des clefs pour accès rapides
	int						m_elementAllocCount;	///< Nombre d'éléments alloués

	int						m_elementCount;			///< Nombre d'éléments actifs
	int						m_iFirstFreeElement;	///< Premier élément NULL de la liste (pour le fillGap)

	bool					m_bAllowDuplicatedKey;	///< Autorise ou non plusieurs éléments avec la même clef

	LISTEXT_KEY_ORDER_STATE	m_iKeyOrderState;		///< Indicateur de l'état de tri de la liste (tri par clé pour la recherche dichotomique du GetByKey)
};

#endif /* __TOOLKIT__EXTLIST_H */
