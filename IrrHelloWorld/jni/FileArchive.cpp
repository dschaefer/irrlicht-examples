/*
 * FileArchive.cpp
 *
 *  Created on: Oct 12, 2010
 *      Author: dschaefer
 */

#include "FileArchive.h"
#include <android/log.h>
#include "ReadFile.h"

#define LOGTAG "IrrArchive"

AndroidFileArchive::AndroidFileArchive(ArchiveHelper & archiveHelper)
: mArchiveHelper(archiveHelper) {
}

AndroidFileArchive::~AndroidFileArchive() {
}

IReadFile * AndroidFileArchive::createAndOpenFile(const path& filename) {
	__android_log_print(ANDROID_LOG_INFO, LOGTAG, "open file: %s", filename.c_str());
	return new AndroidReadFile(mArchiveHelper, filename);
}

IReadFile * AndroidFileArchive::createAndOpenFile(u32 index) {
	__android_log_print(ANDROID_LOG_INFO, LOGTAG, "open file #%d", index);
	return new AndroidReadFile(mArchiveHelper, "not sure");
}

const IFileList * AndroidFileArchive::getFileList() const {
	__android_log_print(ANDROID_LOG_INFO, LOGTAG, "get file list");
	return NULL;
}
