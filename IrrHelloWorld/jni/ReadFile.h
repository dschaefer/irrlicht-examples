/*
 * ReadFile.h
 *
 *  Created on: Oct 12, 2010
 *      Author: dschaefer
 */

#ifndef READFILE_H_
#define READFILE_H_

#include <IReadFile.h>
#include <jni.h>

using namespace irr;
using namespace io;

class ArchiveHelper;

class AndroidReadFile: public IReadFile {
public:
	AndroidReadFile(ArchiveHelper & archiveHelper, const path & filename);
	virtual ~AndroidReadFile();

	virtual s32 read(void* buffer, u32 sizeToRead);
	virtual bool seek(long finalPos, bool relativeMovement = false);

	virtual long getSize() const {
		return mSize;
	}

	virtual long getPos() const {
		return mPos;
	}

	virtual const path& getFileName() const {
		return mFilename;
	}

private:
	ArchiveHelper & mArchiveHelper;
	const path & mFilename;
	jobject mInputStream;
	u32 mSize;
	long mPos;
};

#endif /* READFILE_H_ */
