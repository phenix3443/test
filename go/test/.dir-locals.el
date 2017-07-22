((nil . ((eval . (set (make-local-variable 'project-dir)
					  (file-name-directory
					   (let ((d (dir-locals-find-file ".")))
						 (if (stringp d) d (car d))))))
		 (eval . (message "Project directory set to `%s'." project-dir))))

 (go-mode . ((eval . (setenv "GOPATH" (concat (getenv "GOPATH") ":" project-dir)))
			 ))
 )
