/*
 * FileArchive.h
 *
 *  Created on: Oct 12, 2010
 *      Author: dschaefer
 */

#ifndef FILEARCHIVE_H_
#define FILEARCHIVE_H_

#include <IFileArchive.h>

using namespace irr;
using namespace io;

class ArchiveHelper;

class AndroidFileArchive : public IFileArchive {
public:
	AndroidFileArchive(ArchiveHelper & archiveHelper);
	virtual ~AndroidFileArchive();

	virtual IReadFile* createAndOpenFile(const path& filename);
	virtual IReadFile* createAndOpenFile(u32 index);
	virtual const IFileList* getFileList() const;

private:
	ArchiveHelper & mArchiveHelper;
};

#endif /* FILEARCHIVE_H_ */
