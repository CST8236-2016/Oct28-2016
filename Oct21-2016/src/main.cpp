#include <SFML/Graphics.hpp>
#include <SFML\OpenGL.hpp>

int main(int argc, char *argv)
{
  sf::RenderWindow window(sf::VideoMode(400, 400), "Template", sf::Style::Titlebar | sf::Style::Close);

  /*sf::Texture dogeTexture;
  bool success = dogeTexture.loadFromFile("res/doge.jpg");

  sf::Sprite dogeSprite;
  dogeSprite.setTexture(dogeTexture);
  dogeSprite.setScale(0.25f, 0.25f);*/

  sf::Image dogeImage;
  dogeImage.loadFromFile("res/doge.jpg");

  // Tell OpenGL that we want to use 2D textures. 
  glEnable(GL_TEXTURE_2D);

  // Tell OpenGL that we want to use lighting.
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);

  // Generate a texture in OpenGL, and retrieve its ID so that we can access it.
  GLuint dogeTextureID;
  glGenTextures(1, &dogeTextureID);

  /* 'Bind' our texture to the active texture space so that all of our operations
   * are done to it. */
  glBindTexture(GL_TEXTURE_2D, dogeTextureID);

  glTexImage2D(GL_TEXTURE_2D, // specifies that we're working on the active texture.
    0, // ignore.
    GL_RGBA, // specifies that making a texture that has RGBA data.
    dogeImage.getSize().x, // specify the width of the texture.
    dogeImage.getSize().y, // specify the height of the texture.
    0, // no border
    GL_RGBA, // specifies that we're working with an image that has RGBA data.
    GL_UNSIGNED_BYTE, // specifies the format of the RGBA data (in this case, everything is 0-255)
    dogeImage.getPixelsPtr() // specifies the actual image data.
    );

  /* Telling OpenGL that we want our active texture to magnify and minimize in 
   * linear fashion. */
  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

  /* Telling OpenGL how we want to represent our texture when we try to draw past its bounds. */
  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

  float positionZ = 0.5f;

  sf::Event evt;
  sf::Clock appTimer;
  while (window.isOpen()) {
    float deltaTime = appTimer.restart().asSeconds();

    while (window.pollEvent(evt)) {
      if (evt.type == sf::Event::Closed) {
        window.close();
      }
    }

    //dogeSprite.move(20.0f * deltaTime, 0.0f); // glTranslate
    //dogeSprite.rotate(20.0f); // glRotate
    //dogeSprite.scale(0.25, 0.25f); // glScale

    // do stuff.
    //window.clear();

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //positionZ += 0.1 * deltaTime;
    GLfloat position[] = { 0.0f, 0.0f, positionZ, 0.0f };
    glLightfv(GL_LIGHT0, GL_POSITION, position);

    GLenum error = glGetError();

    float offset = 0.25f;

    //draw stuff
    glRotatef(45.0f * deltaTime, 0.0f, 1.0f, 0.0f); // rotating 45 degrees on the z axis.

    glPushMatrix();
    //glRotatef(90.0f, 0.0f, 1.0f, 0.0f); // rotating 45 degrees on the z axis.

    // Begin our drawing block.
    glBegin(GL_QUADS);

    // Draw a vertex at (0.0f, 0.0f, 0.0f).
    /*glColor3f(1.0f, 1.0f, 1.0f);
    glTexCoord2f()
    glVertex3f(0.0f, 0.0f, 0.0f);
    
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(-offset, -offset, 0.0f);
    
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-offset, offset, 0.0f);
    
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(offset, offset, 0.0f);
    
    glColor3f(0.0f, 1.0f, 1.0f);
    glVertex3f(offset, -offset, 0.0f);*/

    //glColor3f(1.0f, 0.0f, 0.0f);
    glTexCoord2f(0.0f, 0.0f);
    //glNormal3f(0.0f, 0.0f, 1.0f);
    glVertex3f(-offset, -offset, offset);

    //glColor3f(0.0f, 1.0f, 0.0f);
    glTexCoord2f(0.0f, 1.0f);
    //glNormal3f(0.0f, 0.0f, 1.0f);
    glVertex3f(-offset, offset, offset);

    //glColor3f(0.0f, 0.0f, 1.0f);
    glTexCoord2f(1.0f, 1.0f);
    //glNormal3f(0.0f, 0.0f, 1.0f);
    glVertex3f(offset, offset, offset);

    //glColor3f(0.0f, 1.0f, 1.0f);
    glTexCoord2f(1.0f, 0.0f);
    //glNormal3f(0.0f, 0.0f, 1.0f);
    glVertex3f(offset, -offset, offset);

    // End our drawing block.
    glEnd();

    glPopMatrix();

    window.display();
  }

  return 0;
}