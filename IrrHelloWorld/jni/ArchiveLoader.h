/*
 * ArchiveLoader.h
 *
 *  Created on: Oct 11, 2010
 *      Author: dschaefer
 */

#ifndef ARCHIVELOADER_H_
#define ARCHIVELOADER_H_

#include <IFileArchive.h>

using namespace irr;
using namespace io;

class AndroidArchiveLoader : public IArchiveLoader {
public:
	AndroidArchiveLoader();
	virtual ~AndroidArchiveLoader();

	virtual bool isALoadableFileFormat(const path& filename) const;

	virtual bool isALoadableFileFormat(io::IReadFile* file) const;

	virtual bool isALoadableFileFormat(E_FILE_ARCHIVE_TYPE fileType) const;

	virtual IFileArchive* createArchive(const path& filename, bool ignoreCase, bool ignorePaths) const;

	virtual IFileArchive* createArchive(io::IReadFile* file, bool ignoreCase, bool ignorePaths) const;
};

#endif /* ARCHIVELOADER_H_ */
