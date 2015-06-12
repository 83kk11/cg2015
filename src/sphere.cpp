#include "sphere.hpp"

Sphere::Sphere(GLfloat _x, GLfloat _y, GLfloat _z, GLfloat _radius) {
	x = _x;
	y = _y;
	z = _z;
	radius = _radius;

	vx = randomFloat(-0.1, 0.1);
	vy = randomFloat(-0.1, 0.1);
	vz = randomFloat(-0.1, 0.1);

	color[0] = randomFloat(0.0, 1.0);
	color[1] = randomFloat(0.0, 1.0);
	color[2] = randomFloat(0.0, 1.0);
	color[3] = 1.0f;
}

void Sphere::update() {
	x += vx;
	y += vy;
	z += vz;
}

void Sphere::render() {
	GLfloat colorWhite[4] = {1.0, 1.0, 1.0, 1.0};
	GLfloat colorAmbient[4] = {0.2, 0.2, 0.2, 1.0};
	glMaterialfv(GL_FRONT, GL_DIFFUSE, color);
	glMaterialfv(GL_FRONT, GL_AMBIENT, color);
	gluSphere(gluNewQuadric(), radius, 24, 24);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, colorWhite);
	glMaterialfv(GL_FRONT, GL_AMBIENT, colorAmbient);
};

bool Sphere::isColliding(Sphere *otherSphere) {
	GLfloat dx = fabs(x - otherSphere->x);
	GLfloat dy = fabs(y - otherSphere->y);
	GLfloat dz = fabs(z - otherSphere->z);

	float distance = dx * dx + dy * dy + dz * dz;
	float minDistance = radius + otherSphere->radius;

	return minDistance >= distance * distance;
}
