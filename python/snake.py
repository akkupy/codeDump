import pygame, random
from pygame.locals import *

def apple_random_position():
	x = random.randint(0,590)
	y = random.randint(0,590)
	return (x//10 * 10, y//10 * 10)

#Colisão com a maçã
def collision(s1, s2):
	return (s1[0] == s2[0]) and (s1[1] == s2[1])

def collision_lose(position):
	return (position[0] == 0) or (position[1] == 0) or (position[0] == 600) or (position[1] == 600)

def self_collision(position, snake):
	return (snake.count(position) > 1)

pygame.init()
screen = pygame.display.set_mode((600,600))
pygame.display.set_caption('Snake')

#direções
up = 0
right = 1
down = 2
left = 3

snake = [(200,200), (210,200), (220,200)]
snake_direction = left
snake_skin = pygame.Surface((10,10))
snake_skin.fill((255,255,255))

apple_position = apple_random_position()
apple = pygame.Surface((10,10))
apple.fill((255,0,0))

clock = pygame.time.Clock()

while True:
	clock.tick(20)

	for event in pygame.event.get():
		if event.type == QUIT:
			pygame.quit()
		if event.type == KEYDOWN:
			if event.key == K_UP and not snake_direction == down:
				snake_direction = up
			if event.key == K_DOWN and not snake_direction == up:
				snake_direction = down
			if event.key == K_RIGHT and not snake_direction == left:
				snake_direction = right
			if event.key == K_LEFT and not snake_direction == right:
				snake_direction = left

	if collision(snake[0], apple_position):
		apple_position = apple_random_position()
		snake.append((0,0))

	if collision_lose(snake[0]) or self_collision(snake[0], snake):
		pygame.quit()



	for i in range(len(snake) - 1, 0, -1):
		snake[i] = (snake[i-1][0], snake[i-1][1])

	if snake_direction == up:
		snake[0] = (snake[0][0], snake[0][1] - 10)
	if snake_direction == down:
		snake[0] = (snake[0][0], snake[0][1] + 10)
	if snake_direction == right:
		snake[0] = (snake[0][0] + 10, snake[0][1])
	if snake_direction == left:
		snake[0] = (snake[0][0] - 10, snake[0][1])

	screen.fill((0,0,0))
	screen.blit(apple, apple_position)
	for position in snake:
		screen.blit(snake_skin,position)

	pygame.display.update()