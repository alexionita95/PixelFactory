#include <SFML/Graphics.hpp>

int main()
{
    using namespace std::literals::string_literals;
    auto window = sf::RenderWindow{ { 800u, 600u }, "Pixel Factory"s };
    window.setFramerateLimit(144);

    while (window.isOpen())
    {
        for (auto event = sf::Event{}; window.pollEvent(event);)
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        window.clear();
        window.display();
    }
}