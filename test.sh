#!/usr/bin/env bash

echo "Проверяю на корректность примеры из каталога example"
sh ./example/test-example.sh || continue

echo "Запускаю тест coverage"
sh ./coverage/coverage.sh | tail -n 2 || continue
