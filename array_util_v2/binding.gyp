{
  "targets": [
    {
      "target_name": "array_util",
      "sources": [
        "array_util.cc"
      ],
      "include_dirs": [
        "<!(node -e \"require('nan')\")"
        ]
    }
  ]
}
