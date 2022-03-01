#ifndef SIMPLE_H
#define SIMPLE_H

#include <Godot.hpp>

#include <Input.hpp>
#include <Reference.hpp>
#include <Sprite.hpp>
#include <cstdio>
#include "tensorflow/lite/interpreter.h"
#include "tensorflow/lite/kernels/register.h"
#include "tensorflow/lite/model.h"
#include "tensorflow/lite/optional_debug_tools.h"

class Simple : public godot::Reference {
	GODOT_CLASS(Simple, godot::Reference)

	godot::String data;
	 std::unique_ptr<tflite::FlatBufferModel> model;

public:
	static void _register_methods();

	void _init();

	godot::String get_data() const;
	void load_model(const godot::String filename);
	
};

class SimpleSprite : public godot::Sprite {
	GODOT_CLASS(SimpleSprite, godot::Sprite)

	godot::Input *_input;

public:
	static void _register_methods();

	void _init();

	void _process(const double p_delta);
};

#endif // SIMPLE_H
