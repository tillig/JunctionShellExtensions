// FSLinks.h
// Updated/modified by Travis Illig
// Original copyright 2000 Mikael Nordell (tamlin@algonet.se)
// Distributed without warranties. Use as you see fit, except for
// commercial purposes.

#pragma once
#include "TMN_Win2k.h"

// Represents the bits that are valid to use in reparse tags.
#define IO_REPARSE_TAG_VALID_VALUES     (0xF000FFFF)

// Macro to determine whether a reparse tag is a valid tag.
#define IsReparseTagValid(_tag) (!((_tag) & ~IO_REPARSE_TAG_VALID_VALUES) && ((_tag) > IO_REPARSE_TAG_RESERVED_RANGE))


namespace FSLinks {
	BOOL CreateJunctionPoint(LPCTSTR szMountDir, LPCTSTR szDestDir);
	BOOL DeleteJunctionPoint(LPCTSTR szMountDir);
	DWORD GetJunctionPointInfo(LPCTSTR szMountDir, LPTSTR  szDestBuff, DWORD   dwBuffSize);
}
