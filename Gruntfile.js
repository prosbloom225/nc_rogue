module.exports = function(grunt) {
    grunt.loadNpmTasks('grunt-shell');
    grunt.loadNpmTasks('grunt-contrib-watch');
    grunt.initConfig({
        shell: {
            greet: {
                command: function(greeting) {
                    return 'echo' + greeting;
                }
            },
            make: {
                command: 'make',
            },
            clean: {
                command: 'make clean',
            },
            execute: {
                command: 'bin/main 2&> out.log',
            },
            test: {
                command: "echo TEST COMPLETE",
            }},
        watch: {
            scripts: {
                files: ['**/*.cpp', '**/*.h'],
                             tasks: ['build'],
                             options: {
                             forever: true,
                             spawn: false,
                             }
            }
        }
    });
    grunt.registerTask('default', ['watch']);
    grunt.registerTask('build', ['shell:make']);
    grunt.registerTask('run', ['shell:clean', 'shell:make', 'shell:execute', 'shell:test']);
    grunt.registerTask('exec', ['shell:execute', 'shell:test']);
    grunt.registerTask('test', ['shell:test']);
};
