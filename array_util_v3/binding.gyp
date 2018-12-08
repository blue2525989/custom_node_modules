{
  "targets": [
    {
      "target_name": "arrayutil",
      "sources": [ "arrayutil.cc", "arrayutil_helper.cc" ],
      "include_dirs": [
        "<!(node -e \"require('nan')\")"
      ]
    }
  ]
}
