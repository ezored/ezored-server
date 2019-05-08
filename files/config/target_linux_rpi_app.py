def run(proj_path, target_name, params):
    return {
        'project_name': 'Sample',
        'build_types': ['Debug', 'Release'],
        'archs': [
            {
                'arch': 'armv7',
                'conan_arch': 'armv7',
                'conan_profile': 'ezored_linux_app_rpi_profile',
            },
        ],
        'assets_dir': 'projects/server/assets',
    }
