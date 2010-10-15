/*
 * ReadFile.cpp
 *
 *  Created on: Oct 12, 2010
 *      Author: dschaefer
 */

#include "ReadFile.h"
#include "ArchiveHelper.h"
#include <android/log.h>

AndroidReadFile::AndroidReadFile(ArchiveHelper & archiveHelper, const path & filename)
: mArchiveHelper(archiveHelper)
, mFilename(filename)
, mPos(0) {
	mSize = mArchiveHelper.getSize(filename);
	mInputStream = mArchiveHelper.openFile(filename);
}

AndroidReadFile::~AndroidReadFile() {
	mArchiveHelper.releaseFile(mInputStream);
}

s32 AndroidReadFile::read(void* buffer, u32 sizeToRead) {
	int n = mArchiveHelper.read(mInputStream, buffer, sizeToRead);
	mPos += n;
	return n;
}

bool AndroidReadFile::seek(long finalPos, bool relativeMovement) {
	if (relativeMovement)
		mPos += finalPos;
	else
		mPos = finalPos;
}
