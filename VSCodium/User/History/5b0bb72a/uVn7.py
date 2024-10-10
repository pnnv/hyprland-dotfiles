import pygame
import random

# Initialize Pygame
pygame.init()

# Screen dimensions
SCREEN_WIDTH = 800
SCREEN_HEIGHT = 400

# Colors
WHITE = (255, 255, 255)
BLACK = (0, 0, 0)

# Dinosaur settings
DINO_WIDTH = 40
DINO_HEIGHT = 40
DINO_JUMP_VELOCITY = -15
GRAVITY = 1

# Obstacle settings
OBSTACLE_WIDTH = 20
OBSTACLE_HEIGHT = 40
OBSTACLE_VELOCITY = -10

# Initialize the screen
screen = pygame.display.set_mode((SCREEN_WIDTH, SCREEN_HEIGHT))
pygame.display.set_caption("Chrome Dino Game")

# Dinosaur class
class Dinosaur:
    def __init__(self):
        self.rect = pygame.Rect(100, SCREEN_HEIGHT - DINO_HEIGHT, DINO_WIDTH, DINO_HEIGHT)
        self.velocity = 0
        self.jumping = False

    def update(self):
        if self.jumping:
            self.velocity += GRAVITY
            self.rect.y += self.velocity
            if self.rect.y >= SCREEN_HEIGHT - DINO_HEIGHT:
                self.rect.y = SCREEN_HEIGHT - DINO_HEIGHT
                self.jumping = False
                self.velocity = 0

    def jump(self):
        if not self.jumping:
            self.jumping = True
            self.velocity = DINO_JUMP_VELOCITY

    def draw(self):
        pygame.draw.rect(screen, BLACK, self.rect)

# Obstacle class
class Obstacle:
    def __init__(self):
        self.rect = pygame.Rect(SCREEN_WIDTH, SCREEN_HEIGHT - OBSTACLE_HEIGHT, OBSTACLE_WIDTH, OBSTACLE_HEIGHT)

    def update(self):
        self.rect.x += OBSTACLE_VELOCITY
        if self.rect.x < 0:
            self.rect.x = SCREEN_WIDTH
            self.rect.y = SCREEN_HEIGHT - OBSTACLE_HEIGHT

    def draw(self):
        pygame.draw.rect(screen, BLACK, self.rect)

# Main game loop
def main():
    clock = pygame.time.Clock()
    dinosaur = Dinosaur()
    obstacle = Obstacle()
    running = True

    while running:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
            elif event.type == pygame.KEYDOWN:
                if event.key == pygame.K_SPACE:
                    dinosaur.jump()

        screen.fill(WHITE)
        dinosaur.update()
        obstacle.update()
        dinosaur.draw()
        obstacle.draw()
        pygame.display.flip()
        clock.tick(30)

    pygame.quit()

if __name__ == "__main__":
    main()
