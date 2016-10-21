#include <SFML/Graphics.hpp>
#include <SFML\OpenGL.hpp>

int main(int argc, char *argv)
{
  sf::RenderWindow window(sf::VideoMode(400, 400), "Template", sf::Style::Titlebar | sf::Style::Close);

  sf::Texture dogeTexture;
  bool success = dogeTexture.loadFromFile("res/doge.jpg");

  sf::Sprite dogeSprite;
  dogeSprite.setTexture(dogeTexture);
  dogeSprite.setScale(0.25f, 0.25f);

  float position = 0.0f;

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

    //draw stuff
   // window.draw(dogeSprite);

    // Begin our drawing block.
    glBegin(GL_QUADS);

    // Draw a vertex at (0.0f, 0.0f, 0.0f).
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(0.1f, -0.1f, 0.0f);
    
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(-0.25f, -0.25f, 0.0f);
    
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-0.25f, 0.25f, 0.0f);
    
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(0.25f, 0.25f, 0.0f);
    
    glColor3f(0.0f, 1.0f, 1.0f);
    glVertex3f(0.25f, -0.25f, 0.0f);

    // End our drawing block.
    glEnd();

    window.display();
  }

  return 0;
}