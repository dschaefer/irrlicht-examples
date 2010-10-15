package doug.irrlicht;

import java.io.IOException;
import java.io.InputStream;

import android.content.res.AssetFileDescriptor;
import android.content.res.AssetManager;
import android.util.Log;

/**
 * Collection of methods called from native to access assets.
 * 
 * @author Doug Schaefer
 */
public class ArchiveHelper {

	private final AssetManager assetManager;
	
	public ArchiveHelper(AssetManager assetManager) {
		this.assetManager = assetManager;
	}
	
	public static String cleanFilename(String filename) {
		if (filename.startsWith("/"))
			return filename.substring(1);
		return filename;
	}
	
	public int getSize(String filename) {
		try {
			AssetFileDescriptor fd = assetManager.openFd(cleanFilename(filename));
			int size = (int)fd.getLength();
			fd.close();
			return size;
		} catch (IOException e) {
			return 0;
		}
	}
	
	public InputStream openFile(String filename) {
		try {
			InputStream in = assetManager.open(cleanFilename(filename), AssetManager.ACCESS_RANDOM);
			return in;
		} catch (IOException e) {
			Log.e("IrrArchive", "opening file", e);
			return null;
		}
	}
	
	public static int read(InputStream in, byte[] buffer) {
		try {
			return in.read(buffer);
		} catch (IOException e) {
			return 0;
		}
	}
}
