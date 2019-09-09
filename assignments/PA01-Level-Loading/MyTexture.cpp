#include "MyTexture.h"
#include "MyGame.h"


namespace GMUCS425
{

  bool MyTexture::loadFromFile( std::string path )
  {
    using namespace std;

  	//Get rid of preexisting texture
  	free();

  	//The final texture
  	SDL_Texture* newTexture = NULL;

  	//Load image at specified path
  	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
  	if( loadedSurface == NULL )
  	{
  		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
  	}
  	else
  	{
  		//Color key image
  		SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 0xFF, 0xFF ) );

  		//Create texture from surface pixels
      newTexture = SDL_CreateTextureFromSurface( getMyGame()->getRenderer(), loadedSurface );
  		if( newTexture == NULL )
  		{
  			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
  		}
  		else
  		{
  			//Get image dimensions
  			mWidth = loadedSurface->w;
  			mHeight = loadedSurface->h;
  		}

  		//Get rid of old loaded surface
  		SDL_FreeSurface( loadedSurface );
  	}

  	//Return success
  	mTexture = newTexture;
  	return mTexture != NULL;
  }

  void MyTexture::free()
  {
  	//Free texture if it exists
  	if( mTexture != NULL )
  	{
  		SDL_DestroyTexture( mTexture );
  		mTexture = NULL;
  		mWidth = 0;
  		mHeight = 0;
  	}
  }

  void MyTexture::setColor( Uint8 red, Uint8 green, Uint8 blue )
  {
  	//Modulate texture rgb
  	SDL_SetTextureColorMod( mTexture, red, green, blue );
  }

  void MyTexture::setBlendMode( SDL_BlendMode blending )
  {
  	//Set blending function
  	SDL_SetTextureBlendMode( mTexture, blending );
  }

  void MyTexture::setAlpha( Uint8 alpha )
  {
  	//Modulate texture alpha
  	SDL_SetTextureAlphaMod( mTexture, alpha );
  }

  void MyTexture::render( int x, int y, SDL_Rect* clip, float scale, float angle,
                          SDL_Point* center, SDL_RendererFlip flip )
  {
  	//Set rendering space and render to screen
  	SDL_Rect renderQuad = { x, y, mWidth, mHeight };

  	//Set clip rendering dimensions
  	if( clip != NULL )
  	{
  		renderQuad.w = static_cast<int>(clip->w*scale);
  		renderQuad.h = static_cast<int>(clip->h*scale);
  	}

  	//Render to screen
  	SDL_RenderCopyEx( getMyGame()->getRenderer(), mTexture, clip, &renderQuad, angle, center, flip );
  }

  int MyTexture::getWidth()
  {
  	return mWidth;
  }

  int MyTexture::getHeight()
  {
  	return mHeight;
  }


}//end namespace GMUCS425
