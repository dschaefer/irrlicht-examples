package doug.irrlicht;

public class GLNative {
	static {
		System.loadLibrary("IrrHelloWorld");
	}
	
	// Pointer to native object
	private int p;

	public GLNative(int width, int height) {
		p = init(width, height);
	}

	public void step() {
		if (p != 0)
			step(p);
	}
	
	public void drop() {
		if (p != 0) {
			drop(p);
			p = 0;
		}
	}
	
    private static native int init(int width, int height);
    private static native void step(int p);
    private static native void drop(int p);
}
