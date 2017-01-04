// TMN_Win2k.cpp
// Updated/modified by Travis Illig
// Original copyright 2000 Mikael Nordell (tamlin@algonet.se)
// Distributed without warranties. Use as you see fit, except for
// commercial purposes.
#include "stdafx.h"

bool TMN_REPARSE_DATA_BUFFER::Init(LPCSTR szJunctionPoint)
{
	if (!szJunctionPoint || !*szJunctionPoint) {
		return false;
	}

	const int cchDest = lstrlenA(szJunctionPoint) + 1;
	if (cchDest > 512) {
		return false;
	}
	wchar_t wszDestMountPoint[512];
	if (!MultiByteToWideChar(CP_THREAD_ACP,
							MB_PRECOMPOSED,
							szJunctionPoint,
							cchDest,
							wszDestMountPoint,
							cchDest))
	{
		return false;
	}

	return Init(wszDestMountPoint);
}

bool TMN_REPARSE_DATA_BUFFER::Init(LPCWSTR wszJunctionPoint)
{
	if (!wszJunctionPoint || !*wszJunctionPoint) {
		return false;
	}

	const WORD nDestMountPointBytes = lstrlenW(wszJunctionPoint) * 2;

	ReparseTag           = IO_REPARSE_TAG_MOUNT_POINT;
	ReparseDataLength    = nDestMountPointBytes + 12;
	Reserved             = 0;
	SubstituteNameOffset = 0;
	SubstituteNameLength = nDestMountPointBytes;
	PrintNameOffset      = nDestMountPointBytes + 2;
	PrintNameLength      = 0;
	lstrcpyW(PathBuffer, wszJunctionPoint);

	return true;
}

int TMN_REPARSE_DATA_BUFFER::BytesForIoControl() const
{
	return ReparseDataLength + TMN_REPARSE_DATA_BUFFER_HEADER_SIZE;
}

