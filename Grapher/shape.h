
#ifndef shape_hpp
#define shape_hpp

class shape {
public:
	virtual void draw();
};

class circle : shape {

public:
	void draw();

};

class square : shape {

public:
	void draw();

};

class triangle : shape {

public:
	void draw();

};

#endif