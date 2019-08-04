#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openframeworks");

	ofBackground(239);
	ofSetLineWidth(3);
	ofEnableDepthTest();
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();
	ofRotateY(ofGetFrameNum());

	auto R = 300.f;
	auto r = 100.f;
	auto u = 0.f;
	auto u_step = 10.f;
	auto v_step = 5.f;
	int param = (ofGetFrameNum() * 2) % 360;

	for (int i = 0; i < 9; i++) {

		ofRotate(20);
		vector<glm::vec3> vertices;
		for (auto v = 0; v < 360; v += v_step) {

			vertices.clear();
			vertices.push_back(this->make_point(R, r, u, v));
			vertices.push_back(this->make_point(R, r, u + u_step, v + v_step));
			vertices.push_back(this->make_point(R, r, u, v + v_step));
			vertices.push_back(this->make_point(R, r, u - u_step, v));

			ofFill();
			ofSetColor(239);
			ofBeginShape();
			ofVertices(vertices);
			ofEndShape(true);

			ofNoFill();
			ofSetColor(39);

			vertices.clear();
			vertices.push_back(this->make_point(R, r + 1, u, v));
			vertices.push_back(this->make_point(R, r + 1, u + u_step, v + v_step));
			vertices.push_back(this->make_point(R, r + 1, u, v + v_step));
			vertices.push_back(this->make_point(R, r + 1, u - u_step, v));

			ofBeginShape();
			ofVertices(vertices);
			ofEndShape(true);

			vertices.clear();
			vertices.push_back(this->make_point(R, r - 1, u, v));
			vertices.push_back(this->make_point(R, r - 1, u + u_step, v + v_step));
			vertices.push_back(this->make_point(R, r - 1, u, v + v_step));
			vertices.push_back(this->make_point(R, r - 1, u - u_step, v));

			ofBeginShape();
			ofVertices(vertices);
			ofEndShape(true);

			u += u_step;
		}
	}

	this->cam.end();
}

//--------------------------------------------------------------
glm::vec3 ofApp::make_point(float R, float r, float u, float v) {

	// 数学デッサン教室 描いて楽しむ数学たち　P.31

	u *= DEG_TO_RAD;
	v *= DEG_TO_RAD;

	auto x = (R + r * cos(u)) * cos(v);
	auto y = (R + r * cos(u)) * sin(v);
	auto z = r * sin(u);

	return glm::vec3(x, y, z);
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}