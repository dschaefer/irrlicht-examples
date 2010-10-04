package doug.irrlicht;

import android.app.Activity;
import android.os.Bundle;

public class IrrHelloWorld extends Activity {
	GLView glView;
	
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        glView = new GLView(getApplication());
        setContentView(glView);
    }
    
    @Override
    protected void onPause() {
    	super.onPause();
    	glView.onPause();
    }
    
    @Override
    protected void onResume() {
    	super.onResume();
    	glView.onResume();
    }
    
}
