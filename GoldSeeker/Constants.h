// Display
// 0: Empty
// 1: Gold
// 2: Solid
// 3: Wall
// 4: Entrance

enum ThreadColor
{
	RED = 0,
	GREEN = 1,
	BLUE = 2,
	NUM_THREADS = 3
};

enum Directions
{
	LEFT = 0,
	RIGHT = 1,
	UP = 2,
	DOWN = 3
};

enum Block_Stats
{
	STATUS_EMPTY = 0,
	STATUS_GOLD = 1,
	STATUS_SOLID = 2,
	STATUS_ENTRANCE = 3
};


enum CaveComplexityOptions
{
	SIMPLE = 1,
	FAIR = 2,
	COMPLEX = 3,
	EXTRA_COMPLEX = 4
};
enum Complexity
{
	BRUSH_SIMPLE = 100, // 20 small, 50 medium, 100 large
	BRUSH_FAIR = 50, // 20 small, 50 medium, 100 large
	BRUSH_COMPLEX = 20, // 20 small, 50 medium, 100 large
	BRUSH_EXTRA_COMPLEX = 5 // 20 small, 50 medium, 100 large
};

enum CaveSizeOptions
{
	SMALL = 1,
	MEDIUM = 2,
	LARGE = 3,
	EXTRA_LARGE = 4
};
enum CaveSize
{
	CAVE_SMALL_ROW = 25,
	CAVE_SMALL_COL = 35,
	CAVE_MEDIUM_ROW = 35,
	CAVE_MEDIUM_COL = 65,
	CAVE_LARGE_ROW = 65,
	CAVE_LARGE_COL = 85,
	CAVE_EXTRA_LARGE_ROW = 55,
	CAVE_EXTRA_LARGE_COL = 155
};

// Cave properties
#define MAP_MARGIN 2
#define FULLNESS_FACTOR 0.5
#define GOLD_RICHNESS 0.03
#define OXYGEN_RICHNESS 14 // 10 = map size

#define BRUSH_LENGTH 4

#define BRUSH_STREAK_FACTOR 4 //



// Block Displays
#define DISPLAY_EMPTY ' '
#define DISPLAY_GOLD '0'
//#define DISPLAY_SOLID 250
#define DISPLAY_SOLID '+'
//#define DISPLAY_ENTRANCE 234
#define DISPLAY_ENTRANCE '@'
#define DISPLAY_COLLIDE 'X'
#define DISPLAY_TRACE '.'
#define DISPLAY_THREAD '*'
//#define DISPLAY_PLAYER 231
#define DISPLAY_PLAYER '&'
#define WALL_HORIZONTAL '-'
//#define WALL_VERTICAL 179
#define WALL_VERTICAL '|'
#define WALL_1 '/'
#define WALL_3 '\\'
//#define WALL_HORIZONTAL_CORRIDOR 205
#define WALL_HORIZONTAL_CORRIDOR '='
//#define WALL_VERTICAL_CORRIDOR 186
#define WALL_VERTICAL_CORRIDOR 'H'
#define WALL_SINGLE_LEFT '<'
#define WALL_SINGLE_RIGHT '>'
#define WALL_SINGLE_UP '^'
#define WALL_SINGLE_DOWN 'V'
#define WALL_ALONE '#'
