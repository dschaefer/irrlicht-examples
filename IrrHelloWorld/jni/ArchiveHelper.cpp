/*
 * ArchiveHelper.cpp
 *
 *  Created on: Oct 14, 2010
 *      Author: dschaefer
 */

#include "ArchiveHelper.h"
#include <android/log.h>

ArchiveHelper::ArchiveHelper(JNIEnv * env, jobject archiveHelper) {
	mEnv = env;
	mArchiveHelper = env->NewGlobalRef(archiveHelper);
}

ArchiveHelper::~ArchiveHelper() {
	mEnv->DeleteGlobalRef(mArchiveHelper);
}

u32 ArchiveHelper::getSize(const path & filename) {
	jclass cls = mEnv->GetObjectClass(mArchiveHelper);
	jmethodID getSize = mEnv->GetMethodID(cls, "getSize", "(Ljava/lang/String;)I");
	mEnv->DeleteLocalRef(cls);

	jstring str = mEnv->NewStringUTF(filename.c_str());
	u32 size = mEnv->CallIntMethod(mArchiveHelper, getSize, str);
	mEnv->DeleteLocalRef(str);

	return size;
}

jobject ArchiveHelper::openFile(const path & filename) {
	jclass cls = mEnv->GetObjectClass(mArchiveHelper);
	jmethodID openFile = mEnv->GetMethodID(cls, "openFile", "(Ljava/lang/String;)Ljava/io/InputStream;");
	mEnv->DeleteLocalRef(cls);

	jstring str = mEnv->NewStringUTF(filename.c_str());
	jobject inputStream = mEnv->CallObjectMethod(mArchiveHelper, openFile, str);
	mEnv->DeleteLocalRef(str);

	return mEnv->NewGlobalRef(inputStream);
}

void ArchiveHelper::releaseFile(jobject inputStream) {
	mEnv->DeleteGlobalRef(inputStream);
}

s32 ArchiveHelper::read(jobject inputStream, void * buffer, u32 sizeToRead) {
	jclass cls = mEnv->GetObjectClass(mArchiveHelper);
	jmethodID read = mEnv->GetStaticMethodID(cls, "read", "(Ljava/io/InputStream;[B)I");

	jbyteArray byteArray = mEnv->NewByteArray(sizeToRead);
	s32 n = mEnv->CallStaticIntMethod(cls, read, inputStream, byteArray);
	mEnv->DeleteLocalRef(cls);

	jboolean isCopy;
	jbyte * b = mEnv->GetByteArrayElements(byteArray, &isCopy);
	for (int i = 0; i < n; ++i)
		((char *)buffer)[i] = b[i];
	mEnv->ReleaseByteArrayElements(byteArray, b, 0);
	mEnv->DeleteLocalRef(byteArray);

	return n;
}
