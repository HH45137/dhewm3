#pragma once

#include "renderer/Image.h"
#include "renderer/Interaction.h"
#include "renderer/MegaTexture.h"
#include "renderer/ModelDecal.h"
#include "renderer/ModelOverlay.h"
#include "renderer/RenderSystem.h"
#include "renderer/RenderWorld.h"


class idRenderSystemLocalGL4 : public idRenderSystem {
public:
	// external functions
	virtual void			Init(void);
	virtual void			Shutdown(void);
	virtual void			InitOpenGL(void);
	virtual void			ShutdownOpenGL(void);
	virtual bool			IsOpenGLRunning(void) const;
	virtual bool			IsFullScreen(void) const;
	virtual int				GetScreenWidth(void) const;
	virtual int				GetScreenHeight(void) const;
	virtual idRenderWorld* AllocRenderWorld(void);
	virtual void			FreeRenderWorld(idRenderWorld* rw);
	virtual void			BeginLevelLoad(void);
	virtual void			EndLevelLoad(void);
	virtual bool			RegisterFont(const char* fontName, fontInfoEx_t& font);
	virtual void			SetColor(const idVec4& rgba);
	virtual void			SetColor4(float r, float g, float b, float a);
	virtual void			DrawStretchPic(const idDrawVert* verts, const glIndex_t* indexes, int vertCount, int indexCount, const idMaterial* material,
		bool clip = true, float x = 0.0f, float y = 0.0f, float w = 640.0f, float h = 0.0f);
	virtual void			DrawStretchPic(float x, float y, float w, float h, float s1, float t1, float s2, float t2, const idMaterial* material);

	virtual void			DrawStretchTri(idVec2 p1, idVec2 p2, idVec2 p3, idVec2 t1, idVec2 t2, idVec2 t3, const idMaterial* material);
	virtual void			GlobalToNormalizedDeviceCoordinates(const idVec3& global, idVec3& ndc);
	virtual void			GetGLSettings(int& width, int& height);
	virtual void			PrintMemInfo(MemInfo_t* mi);

	virtual void			DrawSmallChar(int x, int y, int ch, const idMaterial* material);
	virtual void			DrawSmallStringExt(int x, int y, const char* string, const idVec4& setColor, bool forceColor, const idMaterial* material);
	virtual void			DrawBigChar(int x, int y, int ch, const idMaterial* material);
	virtual void			DrawBigStringExt(int x, int y, const char* string, const idVec4& setColor, bool forceColor, const idMaterial* material);
	virtual void			WriteDemoPics();
	virtual void			DrawDemoPics();
	virtual void			BeginFrame(int windowWidth, int windowHeight);
	virtual void			EndFrame(int* frontEndMsec, int* backEndMsec);
	virtual void			TakeScreenshot(int width, int height, const char* fileName, int downSample, renderView_t* ref);
	virtual void			CropRenderSize(int width, int height, bool makePowerOfTwo = false, bool forceDimensions = false);
	virtual void			CaptureRenderToImage(const char* imageName);
	virtual void			CaptureRenderToFile(const char* fileName, bool fixAlpha);
	virtual void			UnCrop();
	virtual bool			UploadImage(const char* imageName, const byte* data, int width, int height);

public:
	// internal functions
	idRenderSystemLocalGL4(void);
	~idRenderSystemLocalGL4(void);

	void					Clear(void);
	void					SetBackEndRenderer();			// sets tr.backEndRenderer based on cvars
	void					RenderViewToViewport(const renderView_t* renderView, idScreenRect* viewport);

public:
	// renderer globals
	bool					registered;		// cleared at shutdown, set at InitOpenGL

	bool					takingScreenshot;

	int						frameCount;		// incremented every frame
	int						viewCount;		// incremented every view (twice a scene if subviewed)
	// and every R_MarkFragments call

	int						staticAllocCount;	// running total of bytes allocated

	float					frameShaderTime;	// shader time for all non-world 2D rendering

	int						viewportOffset[2];	// for doing larger-than-window tiled renderings
	int						tiledViewport[2];

	// determines which back end to use, and if vertex programs are in use
	backEndName_t			backEndRenderer;
	bool					backEndRendererHasVertexPrograms;
	float					backEndRendererMaxLight;	// 1.0 for standard, unlimited for floats
	// determines how much overbrighting needs
	// to be done post-process

	idVec4					ambientLightVector;	// used for "ambient bump mapping"

	float					sortOffset;				// for determinist sorting of equal sort materials

	idList<idRenderWorldLocal*>worlds;

	idRenderWorldLocal* primaryWorld;
	renderView_t			primaryRenderView;
	viewDef_t* primaryView;
	// many console commands need to know which world they should operate on

	const idMaterial* defaultMaterial;
	idImage* testImage;
	idCinematic* testVideo;
	float					testVideoStartTime;

	idImage* ambientCubeImage;	// hack for testing dependent ambient lighting

	viewDef_t* viewDef;

	performanceCounters_t	pc;					// performance counters

	drawSurfsCommand_t		lockSurfacesCmd;	// use this when r_lockSurfaces = 1
	//renderView_t			lockSurfacesRenderView;
	viewDef_t				lockSurfacesViewDef; // of locked position/view
	viewDef_t				lockSurfacesRealViewDef; // of actual player position

	viewEntity_t			identitySpace;		// can use if we don't know viewDef->worldSpace is valid
	int						stencilIncr, stencilDecr;	// GL_INCR / INCR_WRAP_EXT, GL_DECR / GL_DECR_EXT

	renderCrop_t			renderCrops[MAX_RENDER_CROPS];
	int						currentRenderCrop;

	// GUI drawing variables for surface creation
	int						guiRecursionLevel;		// to prevent infinite overruns
	class idGuiModel* guiModel;
	class idGuiModel* demoGuiModel;

	// DG: remember the original glConfig.vidWidth/Height values that get overwritten in BeginFrame()
	//     so they can be reset in EndFrame() (Editors tend to mess up the viewport by using BeginFrame())
	int						origWidth;
	int						origHeight;
};
