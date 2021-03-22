workspace "Chess Game"
   configurations { "Debug", "Release" }

project "Chess Game"
   kind "ConsoleApp"
   language "C++"
   files { "**.h", "**.cpp" }

   filter { "configurations:Debug" }
      defines { "DEBUG" }
      symbols "On"

   filter { "configurations:Release" }
      defines { "NDEBUG" }
      optimize "On"