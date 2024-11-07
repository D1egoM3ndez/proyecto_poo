# proyecto_poo
Descripción
Este proyecto es una simulación básica de batalla Pokémon en C++ que permite al usuario crear, entrenar y utilizar Pokémon en batallas, donde puede elegir los ataques. Es un ejercicio de programación orientada a objetos que emplea conceptos como clases, encapsulamiento y métodos para simular las interacciones y mecánicas básicas del universo Pokémon.

Características
Clases Base:

Pokemon: Define atributos básicos del Pokémon, como nombre, nivel, vida y tipo. Permite entrenarlo para subir de nivel.
Entrenador: Representa a un entrenador con atributos como nombre, ciudad de origen y tipo preferido. Puede viajar a diferentes ciudades y cambiar de tipo.
Ataque: Contiene los atributos de un ataque (nombre, poder, precisión y tipo) y métodos para simular el uso del ataque y restaurar su precisión.
Funciones Principales:

Entrenar Pokémon: El entrenador puede entrenar a sus Pokémon, aumentando su nivel y poder.
Viajar: El entrenador puede cambiar de ciudad, representando su exploración en el mundo.
Batalla Pokémon: El usuario puede seleccionar ataques en un combate por turnos contra otro Pokémon.
Selección de Ataques: El usuario elige los ataques disponibles para enfrentar al oponente y reduce su vida hasta vencerlo.
Batalla Interactiva:

Los Pokémon realizan ataques por turnos, y el usuario selecciona los ataques de su Pokémon para reducir la vida del oponente.
La precisión del ataque puede reducirse con cada uso, simulando desgaste, y puede ser restaurada a su valor inicial.
