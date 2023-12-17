#include "tr_local.h"


idRenderSystemLocalGL4::idRenderSystemLocalGL4(void)
{
	Clear();
}

idRenderSystemLocalGL4::~idRenderSystemLocalGL4(void)
{

}

void idRenderSystemLocalGL4::Clear(void)
{
	registered = false;
	frameCount = 0;
	viewCount = 0;
	staticAllocCount = 0;
	frameShaderTime = 0.0f;
	viewportOffset[0] = 0;
	viewportOffset[1] = 0;
	tiledViewport[0] = 0;
	tiledViewport[1] = 0;
	backEndRenderer = BE_BAD;
	backEndRendererHasVertexPrograms = false;
	backEndRendererMaxLight = 1.0f;
	ambientLightVector.Zero();
	sortOffset = 0;
	worlds.Clear();
	primaryWorld = NULL;
	memset(&primaryRenderView, 0, sizeof(primaryRenderView));
	primaryView = NULL;
	defaultMaterial = NULL;
	testImage = NULL;
	ambientCubeImage = NULL;
	viewDef = NULL;
	memset(&pc, 0, sizeof(pc));
	memset(&lockSurfacesCmd, 0, sizeof(lockSurfacesCmd));
	memset(&identitySpace, 0, sizeof(identitySpace));
	stencilIncr = 0;
	stencilDecr = 0;
	memset(renderCrops, 0, sizeof(renderCrops));
	currentRenderCrop = 0;
	guiRecursionLevel = 0;
	guiModel = NULL;
	demoGuiModel = NULL;
	takingScreenshot = false;
}

void idRenderSystemLocalGL4::SetBackEndRenderer()
{
}

void idRenderSystemLocalGL4::RenderViewToViewport(const renderView_t* renderView, idScreenRect* viewport)
{
}

void idRenderSystemLocalGL4::Init(void)
{

}

void idRenderSystemLocalGL4::Shutdown(void)
{
}

void idRenderSystemLocalGL4::InitOpenGL(void)
{
}

void idRenderSystemLocalGL4::ShutdownOpenGL(void)
{
}

bool idRenderSystemLocalGL4::IsOpenGLRunning(void) const
{
	return false;
}

bool idRenderSystemLocalGL4::IsFullScreen(void) const
{
	return false;
}

int idRenderSystemLocalGL4::GetScreenWidth(void) const
{
	return 0;
}

int idRenderSystemLocalGL4::GetScreenHeight(void) const
{
	return 0;
}

idRenderWorld* idRenderSystemLocalGL4::AllocRenderWorld(void)
{
	return nullptr;
}

void idRenderSystemLocalGL4::FreeRenderWorld(idRenderWorld* rw)
{
}

void idRenderSystemLocalGL4::BeginLevelLoad(void)
{
}

void idRenderSystemLocalGL4::EndLevelLoad(void)
{
}

bool idRenderSystemLocalGL4::RegisterFont(const char* fontName, fontInfoEx_t& font)
{
	return false;
}

void idRenderSystemLocalGL4::SetColor(const idVec4& rgba)
{
}

void idRenderSystemLocalGL4::SetColor4(float r, float g, float b, float a)
{
}

void idRenderSystemLocalGL4::DrawStretchPic(const idDrawVert* verts, const glIndex_t* indexes, int vertCount, int indexCount, const idMaterial* material, bool clip, float x, float y, float w, float h)
{
}

void idRenderSystemLocalGL4::DrawStretchPic(float x, float y, float w, float h, float s1, float t1, float s2, float t2, const idMaterial* material)
{
}

void idRenderSystemLocalGL4::DrawStretchTri(idVec2 p1, idVec2 p2, idVec2 p3, idVec2 t1, idVec2 t2, idVec2 t3, const idMaterial* material)
{
}

void idRenderSystemLocalGL4::GlobalToNormalizedDeviceCoordinates(const idVec3& global, idVec3& ndc)
{
}

void idRenderSystemLocalGL4::GetGLSettings(int& width, int& height)
{
}

void idRenderSystemLocalGL4::PrintMemInfo(MemInfo_t* mi)
{
}

void idRenderSystemLocalGL4::DrawSmallChar(int x, int y, int ch, const idMaterial* material)
{
}

void idRenderSystemLocalGL4::DrawSmallStringExt(int x, int y, const char* string, const idVec4& setColor, bool forceColor, const idMaterial* material)
{
}

void idRenderSystemLocalGL4::DrawBigChar(int x, int y, int ch, const idMaterial* material)
{
}

void idRenderSystemLocalGL4::DrawBigStringExt(int x, int y, const char* string, const idVec4& setColor, bool forceColor, const idMaterial* material)
{
}

void idRenderSystemLocalGL4::WriteDemoPics()
{
}

void idRenderSystemLocalGL4::DrawDemoPics()
{
}

void idRenderSystemLocalGL4::BeginFrame(int windowWidth, int windowHeight)
{
}

void idRenderSystemLocalGL4::EndFrame(int* frontEndMsec, int* backEndMsec)
{
}

void idRenderSystemLocalGL4::TakeScreenshot(int width, int height, const char* fileName, int downSample, renderView_t* ref)
{
}

void idRenderSystemLocalGL4::CropRenderSize(int width, int height, bool makePowerOfTwo, bool forceDimensions)
{
}

void idRenderSystemLocalGL4::CaptureRenderToImage(const char* imageName)
{
}

void idRenderSystemLocalGL4::CaptureRenderToFile(const char* fileName, bool fixAlpha)
{
}

void idRenderSystemLocalGL4::UnCrop()
{
}

bool idRenderSystemLocalGL4::UploadImage(const char* imageName, const byte* data, int width, int height)
{
	return false;
}
