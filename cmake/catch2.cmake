# Télécharger Catch2 depuis GitHub pour les tests unitaires
include(FetchContent)
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG v3.7.0
)
FetchContent_MakeAvailable(Catch2)