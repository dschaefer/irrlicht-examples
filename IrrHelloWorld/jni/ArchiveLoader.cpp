/*
 * ArchiveLoader.cpp
 *
 *  Created on: Oct 11, 2010
 *      Author: dschaefer
 */

#include "ArchiveLoader.h"
#include <android/log.h>

#define LOGTAG "IrrArchive"

AndroidArchiveLoader::AndroidArchiveLoader() {
	__android_log_print(ANDROID_LOG_INFO, LOGTAG, "Created Archive Loader");
}

AndroidArchiveLoader::~AndroidArchiveLoader() {
	// TODO Auto-generated destructor stub
}

bool AndroidArchiveLoader::isALoadableFileFormat(const path& filename) const {
	__android_log_print(ANDROID_LOG_INFO, LOGTAG, "path: %s", filename.c_str());
	if (filename == "<android>")
		return true;
	return false;
}

bool AndroidArchiveLoader::isALoadableFileFormat(io::IReadFile* file) const {
	__android_log_print(ANDROID_LOG_INFO, LOGTAG, "readFile: %s", file->getFileName().c_str());
	return false;
}

bool AndroidArchiveLoader::isALoadableFileFormat(E_FILE_ARCHIVE_TYPE fileType) const {
	__android_log_print(ANDROID_LOG_INFO, LOGTAG, "fileType: %d", fileType);
	return false;
}

IFileArchive * AndroidArchiveLoader::createArchive(const path& filename, bool ignoreCase, bool ignorePaths) const {
	__android_log_print(ANDROID_LOG_INFO, LOGTAG, "create path: %s", filename.c_str());
	return NULL;
}

IFileArchive * AndroidArchiveLoader::createArchive(io::IReadFile* file, bool ignoreCase, bool ignorePaths) const {
	__android_log_print(ANDROID_LOG_INFO, LOGTAG, "create readFile: %s", file->getFileName().c_str());
	return NULL;
}
