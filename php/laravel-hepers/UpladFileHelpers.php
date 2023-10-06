<?php

namespace App\Helpers;

class SortDatabaseHelper
{
    /**
     * Sort the database table by the given column.
     *
     * @param string $column
     * @param string $direction
     * @return string
     */
    public static function sort(string $column, string $direction): string
    {
        $result = '';

        if (!in_array($direction, ['asc', 'desc'])) {
            $direction = 'asc';
        }

        if ($direction == 'desc') {
            $result = '-';
        }

        return $result . $column;
    }
}
