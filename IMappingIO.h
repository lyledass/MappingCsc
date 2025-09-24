#ifndef	_IMAPPING_IO_H
#define _IMAPPING_IO_H

typedef		void*	TUserData;

// Generic interface to Read/Write on a card
class IMappingIO {

public:
	virtual TCRD_RESULT Read(unsigned int iP1, unsigned int iP2, size_t uDataLen, LPBIT pOutData, TUserData userData) = 0;

	virtual TCRD_RESULT Write(unsigned int iP1, unsigned int iP2, size_t uDataLen, LPCBIT pInData, TUserData userData) = 0;

	virtual bool IsPosP2InBits() const = 0;
};

#endif //_IMAPPING_IO_H
