/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sound.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roespici <roespici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 07:35:58 by roespici          #+#    #+#             */
/*   Updated: 2024/07/03 15:25:25 by roespici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long_bonus.h"

void	ft_init_sound(void)
{
	if (MUSIC)
	{
		if (SDL_Init(SDL_INIT_AUDIO) == -1)
		{
			SDL_Log("Impossible de charger la SDL2 en memoire > %s\n", \
			SDL_GetError());
			SDL_Quit();
		}
		if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, \
			1024) != 0)
			ft_error_sdl("Erreur lors de l'ouverture de l'audio\n", NULL);
	}
}

void	ft_error_sdl(const char *message, Mix_Music *musique)
{
	if (MUSIC)
	{
		SDL_Log("Error : %s > %s", message, SDL_GetError());
		if (musique != NULL)
			Mix_FreeMusic(musique);
		Mix_CloseAudio();
		SDL_Quit();
	}
}

static void	ft_sound_condition(t_game *game)
{
	if (MUSIC)
	{
		if (game->state == VICTORY)
		{
			game->event = 2;
			game->music->victory = Mix_LoadMUS("sound/Epona.mp3");
			if (!game->music->victory)
				ft_error_sdl("Victory music not find\n", game->music->victory);
			if (Mix_PlayMusic(game->music->victory, 0) != 0)
				ft_error_sdl("Victory music not play\n", game->music->victory);
		}
		else if (game->state == DEFEAT)
		{
			game->music->defeat = Mix_LoadMUS("sound/GameOver.mp3");
			if (!game->music->defeat)
				ft_error_sdl("Defeat music not find\n", game->music->defeat);
			if (Mix_PlayMusic(game->music->defeat, 0) != 0)
				ft_error_sdl("Defeat music not play\n", game->music->defeat);
		}
	}
}

void	ft_sound(t_game *game)
{
	if (MUSIC)
	{
		if (game->event == 0 && game->state == IN_PROGRESS)
		{
			game->music->main = Mix_LoadMUS("sound/Theme.mp3");
			if (!game->music->main)
				ft_error_sdl("Main music not find\n", game->music->main);
			if (Mix_PlayMusic(game->music->main, -1) != 0)
				ft_error_sdl("Main music not play\n", game->music->main);
		}
		else if (game->event == 1 && game->state == IN_PROGRESS)
		{
			Mix_FreeMusic(game->music->main);
			game->music->item = Mix_LoadMUS("sound/Item.mp3");
			if (!game->music->item)
				ft_error_sdl("Item music not find\n", game->music->item);
			if (Mix_PlayMusic(game->music->item, 0) != 0)
				ft_error_sdl("Item music not play\n", game->music->item);
			SDL_Delay(4000);
			Mix_FreeMusic(game->music->item);
		}
		ft_sound_condition(game);
	}
}

void	ft_free_sound(t_game *game)
{
	if (MUSIC)
	{
		if (game->music->main)
			Mix_FreeMusic(game->music->main);
		if (game->music->victory && game->event == 2)
			Mix_FreeMusic(game->music->victory);
		if (game->music->defeat && game->state == DEFEAT)
			Mix_FreeMusic(game->music->defeat);
		if (game->music)
			free(game->music);
		Mix_CloseAudio();
		SDL_Quit();
	}
}
