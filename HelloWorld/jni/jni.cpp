#include <irrlicht.h>

using namespace irr;

using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;


void test() {
	IrrlichtDevice *device =
		createDevice(EDT_OGLES2, dimension2d<u32>(640, 480), 16, false, false, false, 0);

	IVideoDriver * driver = device->getVideoDriver();
	ISceneManager * smgr = device->getSceneManager();
	IGUIEnvironment * guienv = device->getGUIEnvironment();

	guienv->addStaticText(L"Hello World!", rect<s32>(10, 10, 260, 22), true);

	IAnimatedMesh * mesh = smgr->getMesh("../../media/sydney.md2");
	IAnimatedMeshSceneNode * node = smgr->addAnimatedMeshSceneNode(mesh);
	node->setMaterialFlag(EMF_LIGHTING, false);
	node->setMD2Animation(EMAT_STAND);
	node->setMaterialTexture(0, driver->getTexture("../../media/sydney.bmp"));

	smgr->addCameraSceneNode(0, vector3df(0, 30, -40), vector3df(0, 5, 0));

	// TODO this goes in the render frame method.
	while (device->run()) {
		driver->beginScene(true, true, SColor(255, 100, 101, 140));
		smgr->drawAll();
		guienv->drawAll();
		driver->endScene();
	}

	device->drop();
}

size_t mbstowcs(wchar_t * wc, const char * mc, size_t len) {
	for (int i = 0; i < len; i++)
		wc[i] = mc[i];
	return len;
}
