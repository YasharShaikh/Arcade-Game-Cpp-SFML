#pragma once
		
#define SCREEN_WIDTH  768
#define SCREEN_HEIGHT  1136

#define SPLASH_STATE_SHOWTIME_TIME 3
#define TIME_BEFORE_SHOWING_GAME_OVER 3

#define SPLASH_SCENE_BACKGROUND_FILEPATH "Resources/res/Splash Background.png"
#define MAINMENU_SCENE_BACKGROUND_FILEPATH "Resources/res/Main Menu Background.png"
#define PAUSE_BACKGROUND_FILEPATH "Resources/res/Pause Background.png"
#define PAUSE_WINDOW_BACKGROUND_FILEPATH "Resources/res/Pause Window.png"
#define RESUME_BUTTON_BACKGROUND_FILEPATH "Resources/res/Resume Button.png"
#define HOME_BUTTON_BACKGROUND_FILEPATH "Resources/res/Home Button.png"

#define MAINMENU_TITLE_FILEPATH "Resources/res/Game Title.png"
#define MAINMENU_PLAY_BUTTON_FILEPATH "Resources/res/Play Button.png"
#define MAINMENU_PLAY_BUTTON_OUTER_FILEPATH "Resources/res/Play Button Outer.png"

#define GAME_BACKGROUND_FILEPATH "Resources/res/Main Menu Background.png"

#define PAUSE_BUTTON_FILEPATH "Resources/res/Pause Button.png"

#define X_PIECE_FILEPATH "Resources/res/O.png"
#define O_PIECE_FILEPATH "Resources/res/X.png"
#define X_WIN_PIECE_FILEPATH "Resources/res/X Win.png"
#define O_WIN_PIECE_FILEPATH "Resources/res/O Win.png"


//Game over
#define RETRY_BUTTON_FILEPATH "Resources/res/Retry Button.png"

//Game screen
#define GAME_GRID_FILEPATH "Resources/res/Grid.png"




#define GAME_OVER

#define X_PIECE 8 
#define O_PIECE 0
#define EMPTY_PIECE -1
#define PLAYER_PIECE X_PIECE
#define AI_PIECE O_PIECE

#define STATE_PLAYING 98
#define STATE_PAUSE 97
#define STATE_WON 96
#define STATE_LOSE 95
#define STATE_PLACING_PIECE 94
#define STATE_AI_PLAYING 93
#define STATE_DRAW 92
