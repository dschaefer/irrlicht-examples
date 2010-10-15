#include <irrlicht.h>
#include <jni.h>
#include <android/log.h>
#include "ArchiveLoader.h"

#define LOGTAG "IrrHelloWorld"

using namespace irr;

using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

#define CHECKNULL(var) if (!var) { \
	__android_log_print(ANDROID_LOG_ERROR, LOGTAG, #var " is NULL"); \
	return; \
}

class GLNative {
public:
	GLNative(JNIEnv * env, int width, int height, jobject archiveHelper)
	: mArchiveHelper(env, archiveHelper) {
		__android_log_print(ANDROID_LOG_INFO, LOGTAG, "Starting...");
		device = createDevice(EDT_OGLES2, dimension2d<u32>(width, height), 16, false, false, false, 0);

		driver = device->getVideoDriver();
		smgr = device->getSceneManager();
		guienv = device->getGUIEnvironment();
		IFileSystem * fileSystem = device->getFileSystem();

		// The android archive loader
		IArchiveLoader * archiveLoader = new AndroidArchiveLoader(mArchiveHelper);
		fileSystem->addArchiveLoader(archiveLoader);
		archiveLoader->drop();

		fileSystem->addFileArchive("<android>");

		guienv->addStaticText(L"Hello World!", rect<s32>(10, 10, 260, 22), true);

		IAnimatedMesh * mesh = smgr->getMesh("sydney.md2");
		CHECKNULL(mesh);
		IAnimatedMeshSceneNode * node = smgr->addAnimatedMeshSceneNode(mesh);
		CHECKNULL(node);
		node->setMaterialFlag(EMF_LIGHTING, false);
		node->setMD2Animation(EMAT_STAND);
		ITexture * texture = driver->getTexture("sydney.bmp");
		CHECKNULL(texture);
		node->setMaterialTexture(0, texture);

		smgr->addCameraSceneNode(0, vector3df(0, 30, -40), vector3df(0, 5, 0));
	}

	void step() {
		if (device->run()) {
			driver->beginScene(true, true, SColor(255, 100, 101, 140));
			smgr->drawAll();
			guienv->drawAll();
			driver->endScene();
		}
	}

	void drop() {
		device->drop();
	}

private:
	IrrlichtDevice * device;
	IVideoDriver * driver;
	ISceneManager * smgr;
	IGUIEnvironment * guienv;

	ArchiveHelper mArchiveHelper;
};

extern "C"
jint Java_doug_irrlicht_GLNative_init(JNIEnv * env, jclass cls, jint width, jint height, jobject archiveHelper) {
	return (jint)new GLNative(env, width, height, archiveHelper);
}

extern "C"
void Java_doug_irrlicht_GLNative_step(JNIEnv * env, jclass cls, jint p) {
	((GLNative *)p)->step();
}

extern "C"
void Java_doug_irrlicht_GLNative_drop(JNIEnv * env, jclass cls, jint p) {
	GLNative * n = (GLNative *)p;
	n->drop();
	delete n;
}

size_t mbstowcs(wchar_t * wc, const char * mc, size_t len) {
	for (int i = 0; i < len; i++)
		wc[i] = mc[i];
	return len;
}
