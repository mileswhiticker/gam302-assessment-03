#ifndef RENDERER_HPP
#define RENDERER_HPP

class Renderer
{
public:
	static Renderer& GetInstance()
	{
		static Renderer instance;
		return instance;
	}
	//
	bool Init();
	bool Render();
	double GetAppTime();
	double GetDeltaT();
	//
	Renderer::~Renderer();
	//
private:
	Renderer();
	//
	void inject_time_pulse();
	double m_AppTime;
	double m_DeltaT;
	//
};

#endif	//RENDERER_HPP