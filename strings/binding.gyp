{
  "targets": [
    {
      "target_name": "strings",
      "sources": ["main.cpp"],
      "cflags": ["-Wall", "-Wextra", "-ansi", "-O3"],
      "include_dirs" : ["<!(node -e \"require('nan')\")"]
    }
  ]
}
