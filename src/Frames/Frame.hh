////////////////////////////////////////////////////////////////////////
/// \class Viewer::Frame
///
/// \brief   The base class for all frames
///
/// \author  Phil Jones <p.jones22@physics.ox.ac.uk>
///
/// REVISION HISTORY:\n
///     25/06/11 : P.Jones - First Revision, new file. \n
///
/// \detail  All Frames will derive from this, however frames should derive
///          from the 2d or 3d subclass version.
///
////////////////////////////////////////////////////////////////////////

#ifndef __Viewer_Frame__
#define __Viewer_Frame__

#include <queue>
#include <string>

#include <Viewer/FrameCoord.hh>
#include <Viewer/GUIManager.hh>
#include <Viewer/GUIReturn.hh>
#include <Viewer/RWWrapper.hh>

namespace sf
{
  class RenderWindow;
  class Event;
} //::sf

namespace Viewer
{
  class ConfigurationTable;

class Frame
{
public:   
  
  virtual ~Frame() {};

  virtual void NewEvent( sf::Event& event );
   
  virtual void Initialise( ConfigurationTable& configTable );

  virtual void SaveConfiguration( ConfigurationTable& configTable );

  virtual void EventLoop() = 0;
  
  virtual std::string GetName() = 0;
  
  /// Only the GUIManager needs the RWWrapper, if overload RenderGUI then you should know what todo...
  virtual void RenderGUI( sf::RenderWindow& windowApp );
  inline virtual void Render2dT( sf::RenderWindow& windowApp );
  virtual void Render2d( RWWrapper& windowApp ) = 0;
  virtual void Render3d() = 0;

  inline void SetFrameCoord( const FrameCoord& frameCoord );
  inline FrameCoord GetFrameCoord(); 
protected:
  FrameCoord fFrameCoord;
  GUIManager fGUIManager;
  std::queue<GUIReturn> fEvents;
};

void 
Frame::Render2dT( sf::RenderWindow& windowApp ) 
{ 
  RWWrapper wrapper = RWWrapper( windowApp, fFrameCoord );
  Render2d( wrapper ); 
}

void
Frame::SetFrameCoord( const FrameCoord& frameCoord ) 
{
  fFrameCoord = frameCoord;
}

FrameCoord 
Frame::GetFrameCoord()
{
  return fFrameCoord;
}


} // ::Viewer

#endif
