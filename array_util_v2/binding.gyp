# {
#   "targets": [
#     {
#       "target_name": "array_util_master",
#       "sources": [ "array_util_master.cc", "arrayutil.cc" ],
#       "include_dirs": [
#         "<!(node -e \"require('nan')\")"
#       ]
#     }
#   ]
# }


{
  "targets": [
    {
      "target_name": "array_util",
      "sources": [
        "array_util.cc",
        "arrayworker.cc"
      ],
      "include_dirs": [
        "<!(node -e \"require('nan')\")"
        ]
    }
  ]
}
