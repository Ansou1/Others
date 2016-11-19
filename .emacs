;; Load code Lisp Epitech pour les headers (F7 ou ^C-h)

;; (global-font-lock-mode) ;; Permet de suprimer la couleur
;;(load "std.el")
(load "~/.emacs.d/std_comment.el")

(load "~/.emacs.d/sr-speedbar.el")
(require 'sr-speedbar)
(setq sr-speedbar-toggle t)
(sr-speedbar-toggle)
;; show all file
(speedbar-add-supported-extension "")
(add-to-list 'speedbar-fetch-etags-parse-list
	     '("\\" . speedbar-parse-c-or-c++tag))

;;show Prototype
(load "~/.emacs.d/c-eldoc.el")
(add-hook 'emacs-lisp-mode-hook
	  '(lambda ()
	     (turn-on-eldoc-mode)))
(add-hook 'c-mode-hook 'c-turn-on-eldoc-mode)

;; Dev web
(load "~/.emacs.d/nxhtml/autostart.el")
(setq mumamo-chunk-coloring 4)

;; Linum: affichage des numeros de ligne sur le
;; cote. Active avec M-x linum-mode
(load "~/.emacs.d/linum.el")
;; Mettre linum par defaut :
 (custom-set-variables
  '(linum-mode t))
;; Change le format et la couleur d'affichage du linum
(setq linum-format "%d ")
(custom-set-faces
 '(linum ((t (:inherit default :foreground "black" :background "white")))))


;; yasnippet: permet de cree des macro plus complexe (ex: main [TAB])
;; s'integre a l'auto-completition. Pour cree des snippets
;; voir le dossier ~/.emacs.d/snippets
(load "~/.emacs.d/yasnippet.el")
(require 'yasnippet)
(yas/initialize)
(yas/load-directory "~/.emacs.d/snippets")

;; auto-complete (MATSUYAMA): menu graphique d'auto-completition
;; Active avec M-x auto-complete-mode
(load "~/.emacs.d/auto-complete.el")
(load "~/.emacs.d/auto-complete-cpp.el")
(load "~/.emacs.d/auto-complete-yasnippet.el")
(load "~/.emacs.d/auto-complete-extension.el")
(load "~/.emacs.d/auto-complete-gtags.el")
;; Mettre 'autocompletition par defaut :
(require 'auto-complete)
(global-auto-complete-mode t)           ;enable global-mode
(setq ac-auto-start t)                  ;automatically start
(setq ac-dwim t)                        ;Do what i mean
(set-default 'ac-sources '(ac-source-yasnippet ac-source-abbrev ac-source-words-in-buffer))

;; Liste de fonction associe aux raccourcis

(fset 'ggdb
   "\370gdb\C-m\C-m")
(fset 'autopar
   "{\C-m\C-m}\C-[OA\C-i")
(fset 'gdbdisp
   "disp ")
(fset 'closegdb
   "\C-xk\C-m")
(fset 'mpc
   "my_putchar('');\C-[OD\C-[OD\C-[OD")
(fset 'do_header
   "\210\C-k\C-y\C-x\C-s\C-xo\C-y;\C-m\C-x\C-s\C-xo\C-[[1;5B\C-[[1;5B")
(fset 'moved
   "\C-[OB\C-[OB\C-[OB")
(fset 'moveu
   "\C-[OA\C-[OA\C-[OA")
(fset 'mover
   "\C-[OC\C-[OC\C-[OC")
(fset 'movel
   "\C-[OD\C-[OD\C-[OD")
(fset 'headstart
   [C-home down C-right C-right ?\C-[ ?\C-? ?\C-[ ?\C-? ?\C-y C-down C-down C-down ?\C-m ?# ?i ?f ?n ?d ?e ?f ?  ?\C-y ?_ C-left C-left ?\M-u ?\M-u ?\C-e ?\C-m ?# ?  ?d ?e ?f ?i ?n ?e ?  ?\C-y ?_ C-left C-left ?\M-u ?\M-u ?\C-e ?\C-m ?\C-m ?\C-m ?# ?e ?n ?d ?i ?f ?  ?/ ?* ?  ?\C-y ?_ C-left C-left ?! ?\M-u ?\M-u ?\C-e ?  ?* ?/ C-up C-up ?\M-% ?. ?\C-m ?_ ?\C-m ?  ?  ?  ?\C-e up ?\C-x ?o])
(fset 'comment
   "\C-A\C-@\C-@\C-[OB\273")
(fset 'goto_include
   "\C-a\C-[OC\C-[OC\C-[OC\C-[OC\C-[OC\C-[OC\C-[OC\C-[OC\C-[OC\C-[OC\C-@\C-e\C-[OD\367\C-x\C-f../inc/\C-y\C-m")

(fset 'cppclass
   "\C-a\C-k\C-x\C-f\C-y.cpp\C-m\C-[[18~\C-y\C-m\C-m\C-y::\C-y()\C-m{\C-m}\C-m\C-m\C-y::~\C-y()\C-m{\C-m}\C-m\C-x\C-s\C-x3\C-xo\C-x\C-f\C-y.h\C-m\C-[[18~\C-y\C-m\C-m#ifndef \C-y_h_\C-a\C-[OC\C-[OC\C-[OC\C-[OC\C-[OC\C-[OC\C-[OC\C-[OC\365\365\C-e\C-m# define \C-y_h_j\C-?\C-a\C-[OC\C-[OC\C-[OC\C-[OC\C-[OC\C-[OC\C-[OC\C-[OC\C-[OC\365\365\365\C-m#endif /* \C-u\C-y\C-[OC\C-e_h_ \C-?\C-a\C-[OC\C-[OC\C-[OC\C-[OC\C-[OC\C-[OC\C-[OC\C-[OC\C-[OC\C-[OC\C-u\C-u\C-u\365\365\C-[OD /*\C-?\C-?*/\C-[OA\C-m\C-m\C-[OAclass \C-y\C-m{\C-m\C-m};\C-[OApublic:\C-m\C-y();\C-m~\C-y();\C-mprivate:\C-m\C-?\C-?\C-x\C-s\C-xo\C-[OA\C-[OA\C-[OA\C-[OA\C-[OA\C-[OA\C-[OA\C-[OA\C-m\C-m\C-[OA#include \"\C-y.h\"\C-x\C-s\C-[OB\C-[OB\C-[OB\C-[OB\C-[OB\C-[OB\C-[OB\C-[OB\C-[OB\C-[OB")


;; Liste des raccourcis (avec leur effet)

(global-set-key [f1] 'headstart)	;; Protege un .h
(global-set-key [f2] 'do_header)	;; Prototype une fonction
;; [f3] permet de commencer une macro
;; [f4] permet de finir une macro / executer une macro
(global-set-key [f5] 'autopar)		;; Met des parentheses
(global-set-key [f6] 'goto_include)	;; Ouvre le fichier inclue
(global-set-key [f7] 'std-file-header)	;; Header Epitech
(global-set-key [f8] 'sr-speedbar-toggle)		;; Suprise...
(global-set-key [f9] 'gdbdisp)		;; "disp "
(global-set-key [f10] 'closegdb)	;; Ferme un buffer
(global-set-key [f11] 'cppclass)		;; create cpp class
(global-set-key [f12] 'comment)		;; Comment la ligne
(global-set-key "\C-[[1;2A" 'moveu)	;; Shift + fleche pour
(global-set-key "\C-[[1;2B" 'moved)	;;  se deplacer 3 fois
(global-set-key "\C-[[1;2C" 'mover)	;;  plus vite
(global-set-key "\C-[[1;2D" 'movel)	;;  .
(global-set-key [A-up] '(lambda ()		;; Alt + haut ou
			     (interactive)	;;  bas pour faire
			     (scroll-down 1)))	;;  scroller le
						;;  buffer
(global-set-key [A-down] '(lambda ()		;;  .
			     (interactive)	;;  .
			     (scroll-up 1)))	;;  .
(global-set-key "\r" "\C-j")		;; Enter indent automatiquement
(global-set-key [select] "\C-e")	;; La touche [end] fonctionne


;; Permet de mettre en brillance l'accolade ou parenthese
;;  correspondante en C en mettant le cursor dessus

(require 'paren)
(show-paren-mode t)
(setq blink-matching-paren t)
(setq blink-matching-paren-on-screen t)
(setq blink-matching-paren-dont-ignore-comments t)


;; Permet de tapper "inc" suivis de espace pour ecrire "include"
;;  sans se planter...

(abbrev-mode 1)
(define-global-abbrev "inc" "include")


;; Load le fichier .myemacs (par defaut)
(if (file-exists-p "~/.myemacs")
    (load-file "~/.myemacs"))
; EOF

(custom-set-variables
;; Permet de delete des tab avec backspace au lieu de les transformer en espaces
 '(backward-delete-char-untabify-method nil)
;; Permet de faire que la touche TAB indent si le cursor est en debut
;;  de ligne et sinon fait une tabulation (plus besion de M-i)
;; '(c-tab-always-indent nil)
;; Permet de mettre en rouge les espaces en fin de lignes
 '(show-trailing-whitespace t))

(custom-set-variables
 '(global-hl-line-mode t)
 )

(menu-bar-mode -1)

(column-number-mode t)
(line-number-mode t)
(add-hook 'c-mode-hook
	  '(lambda()
	     (require 'whitespace)
	     (setq whitespace-line-column 79)
	     (setq whitespace-style '(lines lines-tail trailing))
	     (global-whitespace-mode t)
	     )
	  )

(font-lock-add-keywords 'c-mode'(("\\<\\([0-9]+\\|0x[0-9a-fA-F]+\\)\\>" . font-lock-doc-face)))
(font-lock-add-keywords 'c-mode'(("\\<\\(free\\|x?malloc\\)\\>" . font-lock-doc-face)))
(font-lock-add-keywords 'c-mode'(("\\<\\(exit\\|self\\)\\>" . font-lock-keyword-face)))
(font-lock-add-keywords 'c-mode'(("\\<\\(STDIN_FILENO\\|STDOUT_FILENO\\|STDERR_FILENO\\)\\>" . font-lock-comment-face)))
(font-lock-add-keywords 'c-mode'(("\\<\\(stdin\\|stdout\\|stderr\\)\\>" . font-lock-comment-face)))
(font-lock-add-keywords 'c-mode'(("\\<\\(TRUE\\|FALSE\\|M_PI\\|EXIT_SUCCESS\\|EXIT_FAILURE\\)\\>" . font-lock-constant-face)))
(font-lock-add-keywords 'c-mode'(("\\<\\(v?\\(f\\|sn?\\)?printf\\|asprintf\\|scanf\\|strn?cmp\\|strlen\\|perror\\|fflush\\)\\>" . font-lock-warning-face)))
(font-lock-add-keywords 'c-mode'(("\\<\\(strn?cpy\\|strn?cat\\|strstr\\|strtou?l\\|strtod\\|strtoc\\|atoi\\|atol\\|atof\\)\\>" . font-lock-warning-face)))
(custom-set-faces
 '(highlight ((t (:height 2.0 :weight bold))))
 '(linum ((t (:foreground "#907c3c"))))
 '(font-lock-function-name-face ((t (:foreground "#0000ff" :weight bold))))
 '(font-lock-comment-delimiter-face ((t (:foreground "#0000ff"))))
 '(font-lock-comment-face ((t (:foreground "#0000ff"))))
 '(font-lock-warning-face ((t (:foreground "#ff0000" :weight bold))))
 '(font-lock-doc-face ((t (:foreground "#00ff00" :weight bold))))
 '(vertical-border ((t (:foreground "#f6f3e8" :background "#111111"))))
 '(mode-line ((default (:foreground "#f6f3e8" :background "#111111"))))
 '(whitespace-line ((t (:foreground "#ff0000" :background "#111111" :weight bold))))
 )
