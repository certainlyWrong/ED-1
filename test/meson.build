project('test', 'c')

add_global_arguments([
    '-DSOME_TOKEN=value',
    '-g',
    ], language: 'c')

subdir('linked_list')

executable('main', 'main.c', link_with: [linked_list])

executable('main2', 'main2.c')

executable('main3', 'main3.c')



