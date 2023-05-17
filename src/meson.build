sightedness_sources = [
  'main.cpp',
]

sightedness_deps = [
	dependency('libadwaita-1', required: true),
	dependency('gtk4', required: true),
	dependency('glib-2.0', required: true),
	dependency('gio-2.0', required: true)
]

executable('sightedness', sightedness_sources,
  dependencies: sightedness_deps,
  install: true,
)

