#include "Block.hpp"

std::mt19937 Block::gen = std::mt19937(1924);
std::uniform_real_distribution<> Block::rand = std::uniform_real_distribution<>(0, 1); 

Block::Block(int x, int y) : _bg_sprite(sf::Vector2f(50, 50)), _bar(sf::Vector2f(400 + x * 50, y * 50), _processTime)
{
    _type = NORMAL;
    _item = nullptr;
    _bg.loadFromFile("./res/textures/world/workbench.png");
    _bg_sprite.setTexture(&_bg);
    _bg_sprite.setPosition(400 + x * 50, y * 50);
    _processTime = 0;
}

Block::Block(int x, int y, Type t) : Block(x, y)
{
    _fg_sprite.setSize(sf::Vector2f(50, 50));
    _type = t;
    switch (t)
    {
        case DECOMPOSER_OUTPUT:
            _fg.loadFromFile("./res/textures/world/decomposer_out.png");
            break;
        case DECOMPOSER :
            _fg.loadFromFile("./res/textures/world/decomposer.png");
            break;
        case SCREWDRIVER :
            _fg.loadFromFile("./res/textures/world/screwdriver.png");
            break;
        case INPUT : 
            _bg.loadFromFile("./res/textures/world/input.png");
            _fg.loadFromFile("./res/textures/world/input.png");
            break;
        default:
        break;
    }
    _fg_sprite.setTexture(&_fg);
    _fg_sprite.setPosition(400 + x * 50, y * 50);
}

Block::~Block()
{
    delete _item;
}

void Block::draw(sf::RenderTarget & target, sf::RenderStates) const
{
    target.draw(_bg_sprite);
    target.draw(_fg_sprite);
    if (_item != nullptr)
        target.draw(*_item);
    if (_processTime != 0)
        target.draw(_bar);
}

bool Block::contains(sf::Vector2f const & pos) const
{
    return _bg_sprite.getGlobalBounds().contains(pos);
}

void Block::update()
{
    float r;
    switch (_type)
    {
        case INPUT:
            r = rand(gen);
            if (_item == nullptr && r < 0.005)
            {
                _item = new BrokenItem("Armure", "item2.png");
                _item->setPosition(_fg_sprite.getPosition());
                Orders::insertOrder(dynamic_cast<BrokenItem *>(_item));
            }
        break;
        case NORMAL:
        break;
        default:
            if (_item != nullptr && RecipesList::getInstance()->exist(_item->getName(), _type))
            {
                if (_item != nullptr)
                {
                    if (_processTime < 1)
                    {
                        _processTime += 0.01;
                        _bar.update();
                    } else
                    {
                        if (getType() == DECOMPOSER)
                        {
                            std::vector<Block *> outputs = MainGame::getInstance()->getDecomposerOut();
                            std::vector<std::string> outs = RecipesList::getInstance()->getRecipeOutput(_item->getName(), getType());
                            if (outputs.size() >= outs.size())
                            {
                                int i = 0;
                                for (auto &&str : outs)
                                {
                                    outputs[i]->setItem(new Item(str, Item::getTextureOf(str)));
                                    ++i;
                                }
                                _item = nullptr;
                            }
                        } else
                        {
                            std::vector<std::string> outs = RecipesList::getInstance()->getRecipeOutput(_item->getName(), getType());
                            delete _item;
                            _item = new Item(outs[0], Item::getTextureOf(outs[0]));
                            _item->setPosition(_fg_sprite.getPosition());
                        }
                        
                    }
                    
                }
                else 
                {
                    _processTime = 0;
                }
            }
            else 
            {
                _processTime = 0;
            }
            break;
    }
}