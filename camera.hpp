#include <GL/gl.h>
#include <math.h>
#include <map>

using namespace std;

class Camera {
	public:
		Camera();
		~Camera();
		GLfloat camX = 0, camY = 1.5, camZ = -5;
		GLfloat vcamX = 1, vcamY = 1, vcamZ = 1;
		GLfloat rcamX = 0, rcamY = 0, rcamZ = 0;
		GLfloat camSpeed = 2.5f;
		GLfloat mouseVSensitivity = 7.0f;
		GLfloat mouseHSensitivity = 7.0f;
		void move(double delta);
		void rotate(int horizontalMovement, int verticalMovement);
		void calcMovement(map<int, bool> keyState);
};