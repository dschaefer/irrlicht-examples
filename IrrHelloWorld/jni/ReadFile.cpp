/*
 * ReadFile.cpp
 *
 *  Created on: Oct 12, 2010
 *      Author: dschaefer
 */

#include "ReadFile.h"

AndroidReadFile::AndroidReadFile(const path & filename)
: mfilename(filename)
, pos(0) {
	size = 0;
}

AndroidReadFile::~AndroidReadFile() {
}

s32 AndroidReadFile::read(void* buffer, u32 sizeToRead) {
	pos += sizeToRead;
}

bool AndroidReadFile::seek(long finalPos, bool relativeMovement) {
	if (relativeMovement)
		pos += finalPos;
	else
		pos = finalPos;
}
