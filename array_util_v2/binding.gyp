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
        "array_util.cc"
      ],
      "include_dirs": [
        "<!(node -e \"require('nan')\")"
        ]
    }
  ]
}


# 'conditions': [
#   ['OS=="mac"', {
#     'libraries': [
#       '<!@(pkg-config --libs <#any necessary packages>)',
#       '-framework OpenCL',
#       '-lc++ -lc++abi'
#     ],
#     'xcode_settings': {
#         'GCC_ENABLE_CPP_EXCEPTIONS': 'YES',
#         'OTHER_CFLAGS': [ '-g', '-mmacosx-version-min=10.7', '-std=c++11', '-stdlib=libc++', '-O3', '-D__STDC_CONSTANT_MACROS', '-D_FILE_OFFSET_BITS=64', '-D_LARGEFILE_SOURCE', '-Wall' ],
#         'OTHER_CPLUSPLUSFLAGS': [ '-g', '-mmacosx-version-min=10.7', '-std=c++11', '-stdlib=libc++', '-O3', '-D__STDC_CONSTANT_MACROS', '-D_FILE_OFFSET_BITS=64', '-D_LARGEFILE_SOURCE', '-Wall' ]
#     }
#   }]
# ]
