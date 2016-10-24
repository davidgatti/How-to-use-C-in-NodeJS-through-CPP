{
  "targets": [
    {
      "target_name": "c_library",
      "sources": ["main.cpp"],
      "libraries": ["-L../c_library", "-ldavid_sum"],
      "cflags": ["-Wall", "-g", "-Wextra", "-ansi", "-O3", "-Wl,-z,defs"],
      "include_dirs" : ["<!(node -e \"require('nan')\")"]
    }
  ]
}