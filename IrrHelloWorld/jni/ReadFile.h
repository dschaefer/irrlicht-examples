/*
 * ReadFile.h
 *
 *  Created on: Oct 12, 2010
 *      Author: dschaefer
 */

#ifndef READFILE_H_
#define READFILE_H_

#include <IReadFile.h>

using namespace irr;
using namespace io;

class AndroidReadFile: public IReadFile {
public:
	AndroidReadFile(const path & filename);
	virtual ~AndroidReadFile();

	virtual s32 read(void* buffer, u32 sizeToRead);
	virtual bool seek(long finalPos, bool relativeMovement = false);

	virtual long getSize() const {
		return size;
	}

	virtual long getPos() const {
		return pos;
	}

	virtual const path& getFileName() const {
		return mfilename;
	}

private:
	const path & mfilename;
	long size;
	long pos;
};

#endif /* READFILE_H_ */
