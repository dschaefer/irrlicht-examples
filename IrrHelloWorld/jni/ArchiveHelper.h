/*
 * ArchiveHelper.h
 *
 *  Created on: Oct 14, 2010
 *      Author: dschaefer
 */

#ifndef ARCHIVEHELPER_H_
#define ARCHIVEHELPER_H_

#include <jni.h>
#include <irrlicht.h>

using namespace irr;
using namespace io;

class ArchiveHelper {
public:
	ArchiveHelper(JNIEnv * env, jobject archiveHelper);
	virtual ~ArchiveHelper();

	u32 getSize(const path & filename);
	jobject openFile(const path & filename);
	void releaseFile(jobject inputStream);
	s32 read(jobject inputStream, void * buffer, u32 sizeToRead);

private:
	JNIEnv * mEnv;
	jobject mArchiveHelper;
};

#endif /* ARCHIVEHELPER_H_ */
