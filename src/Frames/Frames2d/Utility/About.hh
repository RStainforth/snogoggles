////////////////////////////////////////////////////////////////////////
/// \class Viewer::Frames::About
///
/// \brief   About frame, displays viewer information
///
/// \author  Phil Jones <p.g.jones@qmul.ac.uk>
///
/// REVISION HISTORY:\n
///     19/07/11 : P.Jones - First Revision, new file. \n
///     21/02/12 : P.Jones - Second Revision, uses new Rect structure. \n
///
/// \detail  Displays frame rate and (hard coded) viewer revision.
///
////////////////////////////////////////////////////////////////////////

#ifndef __Viewer_Frames_About__
#define __Viewer_Frames_About__

#include <Viewer/Frame.hh>

namespace Viewer
{
  class Text;

namespace Frames
{

class About : public Frame
{
public:
  About( RectPtr rect ) : Frame( rect ) { }
  ~About();

  void Initialise();
 
  virtual void EventLoop();
  
  virtual std::string GetName() { return About::Name(); }
  
  static std::string Name() { return std::string( "About" ); }

  virtual void Render2d( RWWrapper& renderApp,
			 const RenderState& renderState );

  void Render3d( RWWrapper& renderApp,
		 const RenderState& renderState ) { }

private:
  Text* fInfoText;
};

} // ::Frames

} // ::Viewer

#endif
